%{
#include <stdlib.h>
#include <string.h>
#include "tsc.h"
#include "TSLYacc.h"

#define STR_BLOCK 200
#define STR_BLOCK_DELTA 100
#define fileno _fileno

typedef struct _Incl_File{
	YY_BUFFER_STATE	Buffer;
	char* FileName;
	list_entry entry;
} InclFile;

list_entry* inclHeader = NULL;
char* currentFile = ".";

void StrInit();
void StrAppend(char);
char* GetStr();
void StrFree();
int StrLen();
void yyerror(char* s);
char* __thisStr;
int __thisStrLen;
int __thisStrMaxLen;
int __lineNumber = 1;
%}
%x str var lcomment mlcomment incl
%option noyywrap
%%

\"	{StrInit();BEGIN(str);}

<str>\"	{
	TSStr* _strLiteral = StrCreate();
	StrAppendS(_strLiteral, GetStr());
	yylval.strVal = _strLiteral;
	StrFree();
	BEGIN(INITIAL);
	return STRING_LITERAL;
	}
<str>\n	{
	++ __lineNumber;
	StrFree();
	yyerror("Unterminated string");
	}

<str>\\n	{
	StrAppend('\n');
	}
<str>\\r	{
	StrAppend('\r');
	}
<str>\\t	{
	StrAppend('\t');
	}

<str>\\(.|\n)	{
	StrAppend(yytext[1]);
	if(yytext[1] == '\n'){
		++ __lineNumber;
	}
	}
<str>[^\\\n\"]+	{
	char* tmp = yytext;
	while(*tmp)StrAppend(*tmp++);
	}

"//"	{
	BEGIN(lcomment);
	StrInit();
	}
<lcomment>[^\n]*	{
	char* tmp = yytext;
	while(*tmp)StrAppend(*tmp++);
	}
<lcomment>\n	{
	/*printf("comment: %s.\n", GetStr());*/
	StrFree();
	++__lineNumber;
	BEGIN(INITIAL);
	}
"/*"	{
	BEGIN(mlcomment);
	StrInit();
	}
<mlcomment>[^*\n]*	{
	char* tmp = yytext;
	while(*tmp)StrAppend(*tmp++);
	}
<mlcomment>"*"+[^*/\n]*	{
	char* tmp = yytext;
	while(*tmp)StrAppend(*tmp++);
	}
<mlcomment>\n	{
	++__lineNumber;
	StrAppend(yytext[0]);
	}
<mlcomment>"*/"	{
	/*printf("comment<Multiple Lines>: %s.\n", GetStr());*/
	StrFree();
	BEGIN(INITIAL);
	}

\$	{BEGIN(var);StrInit();}
<var>[0-9a-zA-Z_]+	{
	char* temp = yytext;
	while(*temp)StrAppend(*temp++);
	}
<var>[^0-9a-zA-Z_]	{
	TSStr* _varName = StrCreate();
	StrAppendS(_varName, GetStr());
	unput(yytext[0]);
	StrFree();
	if(!_varName->Length || ('0' <= _varName->String[0] && _varName->String[0] <= '9'))
	{
		yyerror("Invalid variable name");
	}
	yylval.strVal = _varName;
	/*printf("Var: %s.\n", _varName->String);*/
	BEGIN(INITIAL);
	return VARIANT;
	}
	
include	{
	BEGIN(incl);
	StrInit();
	if( inclHeader == NULL ){
		inclHeader = (list_entry*) malloc(sizeof(list_entry));
		init_list(inclHeader);
	}
	}
<incl>[ \t]* /*skip all spaces and tabs*/
<incl>\"[^\n\"\t]+\"	{
	char* tmp = yytext + 1;
	InclFile *current = NULL;
	list_entry *entry = NULL;
	int included = 0;

	while(*(tmp+1))StrAppend(*tmp++);
	tmp = GetStr();
	_strlwr_s(tmp, strlen(tmp) + 1);
	included = !strcmp(tmp, currentFile); 
	for_each(inclHeader, entry){
		char* fileName = contain_record(entry, InclFile, entry)->FileName;
		_strlwr_s(fileName, strlen(fileName) + 1);
		if(!strcmp(tmp, fileName)){
			included = 1;
			break;
		}
	}
	if(!included){
		errno_t err;
		err = fopen_s(&yyin, tmp, "r");
		if(err){
			yyerror("failed to open file.");
		}else{
			current = (InclFile*) malloc(sizeof(InclFile));
			current->Buffer = YY_CURRENT_BUFFER;
			current->FileName = currentFile;
			currentFile = tmp;
			push(inclHeader, &current->entry);
			yy_switch_to_buffer( yy_create_buffer(yyin, YY_BUF_SIZE) );
		}
	}else{
		printf("Warning: file (%s) has been included.\n", tmp);
	}
	BEGIN(INITIAL);
	}

0x[a-fA-F0-9]+	|
[0-9]+	{
	TSStr* _numStr = StrCreate();
	StrAppendS(_numStr, yytext);
	yylval.strVal = _numStr;
	return CONSTANT;
	}

function	{
	/*printf("found keyword FUNCTION.\n");*/
	return FUNCTION;
	}
if	{
	/*printf("found keyword IF.\n");*/
	return IF;
	}
for	{
	/*printf("found keyword FOR.\n");*/
	return FOR;
	}
do	{
	/*printf("found keyword DO.\n");*/
	return DO;
	}
while	{
	/*printf("found keyword WHILE.\n");*/
	return WHILE;
	}
else	{
	/*printf("found keyword ELSE.\n");*/
	return ELSE;
	}
\<=	{
	/*printf("found OP OP_LE.\n");*/
	return LE_OP;
	}
>=	{
	/*printf("found OP OP_GE.\n");*/
	return GE_OP;
	}
==	{
	/*printf("found OP EQ.\n");*/
	return EQ_OP;
	}
!=	{
	/*printf("found OP NE.\n");*/
	return NE_OP;
	}
"*="	{
	/*printf("found OP MUL_ASSIGN.\n");*/
	return MUL_ASSIGN;
	}
"/="	{
	/*printf("found OP DIV_ASSIGN.\n");*/
	return DIV_ASSIGN;
	}
"+="	{
	/*printf("found OP ADD_ASSIGN.\n");*/
	return ADD_ASSIGN;
	}
"-="	{
	/*printf("found OP SUB_ASSIGN.\n");*/
	return SUB_ASSIGN;
	}
"%="	{
	/*printf("found OP MOD_ASSIGN.\n");*/
	return MOD_ASSIGN;
	}

[a-zA-Z_][0-9a-zA-Z_]+	{
	char* temp = yytext;
	TSStr* _idStr = StrCreate();
	while(*temp)StrAppendC(_idStr, *temp++);
	/*printf("found identifier: %s.\n", _idStr->String);*/
	yylval.strVal = _idStr;
	return IDENTIFIER;
	}

\n	{++__lineNumber;}
[\t ]	;/*ignore all spaces*/
.	{
	/*printf("found char: %c\n", yytext[0]);*/
	return yytext[0];
	}

<<EOF>>	{
	if( !inclHeader || is_empty(inclHeader) ){
		free(inclHeader);
		yyterminate();
	}else{
		list_entry *entry = NULL;
		pop(inclHeader, entry);
		yy_delete_buffer( YY_CURRENT_BUFFER );
		yy_switch_to_buffer( contain_record(entry, InclFile, entry)->Buffer );
		if( strcmp(contain_record(entry, InclFile, entry)->FileName, ".") ){
			free(contain_record(entry, InclFile, entry)->FileName);
		}
		free(contain_record(entry, InclFile, entry));
	}
	}
%%

void StrInit()
{
	__thisStr = (char*) malloc(STR_BLOCK);
	__thisStrLen = 0;
	__thisStrMaxLen = STR_BLOCK;
	__thisStr[__thisStrLen] = '\0';
}

void StrAppend(char ch)
{
	if(__thisStrLen + 1 >= __thisStrMaxLen)
	{
		char* tempStr;
		int i = 0;
		__thisStrMaxLen += STR_BLOCK_DELTA;
		tempStr = (char*) malloc(__thisStrMaxLen);
		while(__thisStr[i])tempStr[i] = __thisStr[i++];
		tempStr[i] = '\0';
		free(__thisStr);
		__thisStr = tempStr;
	}
	__thisStr[__thisStrLen ++] = ch;
	__thisStr[__thisStrLen] = '\0';
}

char* GetStr()
{	
	return __thisStr;
}

void StrFree()
{
	free(__thisStr);
	__thisStrLen = __thisStrMaxLen = 0;
}
int StrLen()
{
	return __thisStrLen;
}

void yyerror(char *s)
{
	//printf("%d: %s\n", __lineNumber, s);
	printf("syntax error!\n");
	system("pause");
	exit(1);
}