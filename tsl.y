%{
#include "tsee.h"
#include "tsc.h"
extern int yylex();
extern void yyerror();
void echo(const char*, const char*);
%}
%union{
	TSStr* strVal;
	PriExp* priExp;
	Operation* op;
	PostExp* postExp;
	ArgExpList* argExpList;
	UnaryExp* unaryExp;
	MulExp* mulExp;
	AddExp* addExp;
	RelExp* relExp;
	EqExp* eqExp;
	LogAndExp* logAndExp;
	LogOrExp* logOrExp;
	CondExp* condExp;
	AssignExp* assignExp;
	int assignOp;
	Exp* exp;
	IDList* idList;
	Stmt* stmt;
	CompStmt* compStmt;
	StmtList* stmtList;
	ExpStmt* expStmt;
	SelStmt* selStmt;
	ItorStmt* itorStmt;
	TransUnit* transUnit;
	ExtDecl* extDecl;
	FunDef* funDef;
}
%code requires {#include "tsc.h"}
%token <strVal> IDENTIFIER CONSTANT STRING_LITERAL VARIANT
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN
%nonassoc IFX
%nonassoc ELSE
%type <priExp> primary_expression
%type <op> op_expression
%type <postExp> postfix_expression
%type <argExpList> argument_expression_list
%type <unaryExp> unary_expression
%type <mulExp> multiplicative_expression
%type <addExp> additive_expression
%type <relExp> relational_expression
%type <eqExp> equality_expression
%type <logAndExp> logical_and_expression
%type <logOrExp> logical_or_expression
%type <condExp> conditional_expression
%type <assignExp> assignment_expression
%type <assignOp> assignment_operator
%type <exp> expression
%type <idList> identifier_list
%type <stmt> statement
%type <compStmt> compound_statement
%type <stmtList> statement_list
%type <expStmt> expression_statement
%type <selStmt> selection_statement
%type <itorStmt> iteration_statement
%type <transUnit> translation_unit
%type <extDecl> external_declaration
%type <funDef> function_definition

%token IF WHILE DO FOR CONTINUE BREAK RETURN FUNCTION

%start translation_unit
%no-lines
%parse-param {EEProgram* program}
%initial-action	{
	/*Just a mark place*/
}
%%

primary_expression
	: IDENTIFIER	{
	$$ = (PriExp*)_tsmalloc(sizeof(PriExp));
	$$->type = 1; 
	$$->token = $1; 
	printf("Identifier: %s.\n", $1->String);
	}
	| VARIANT	{
	$$ = (PriExp*)_tsmalloc(sizeof(PriExp));
	$$->type = 2; 
	$$->token = $1; 
	printf("Variant: %s.\n", $1->String);
	}
	;

op_expression
	: IDENTIFIER '.' IDENTIFIER	{
	$$ = (Operation*)_tsmalloc(sizeof(Operation));
	$$->component = $1;
	$$->function = $3;
	printf("Operation: %s.%s.\n", $1->String, $3->String);
	}

postfix_expression
	: primary_expression	{
	$$ = (PostExp*)_tsmalloc(sizeof(PostExp));
	$$->type = 1;
	$$->comp.priExp = $1;
	}
	| primary_expression '(' argument_expression_list ')'	{
	$$ = (PostExp*)_tsmalloc(sizeof(PostExp));
	$$->type = 2;
	$$->comp.funCall.priExp = $1;
	$$->comp.funCall.argList = $3;
	}
	| primary_expression '(' ')'	{
	$$ = (PostExp*)_tsmalloc(sizeof(PostExp));
	$$->type = 2;
	$$->comp.funCall.priExp = $1;
	$$->comp.funCall.argList = NULL;
	}
	| op_expression '(' argument_expression_list ')'	{
	$$ = (PostExp*) _tsmalloc(sizeof(PostExp));
	$$->type = 3;
	$$->comp.opCall.op = $1;
	$$->comp.opCall.argList = $3;
	}
	| op_expression '(' ')'	{
	$$ = (PostExp*) _tsmalloc(sizeof(PostExp));
	$$->type = 3;
	$$->comp.opCall.op = $1;
	$$->comp.opCall.argList = NULL;
	}
	| '(' expression ')'	{
	$$ = (PostExp*) _tsmalloc(sizeof(PostExp));
	$$->type = 4;
	$$->comp.exp = $2;
	}
	| CONSTANT	{
	$$ = (PostExp*) _tsmalloc(sizeof(PostExp));
	$$->type = 5;
	$$->comp.number = StrToNum($1);
	printf("Const: %u.\n", $$->comp.number);
	StrDestroy($1);
	}
	| STRING_LITERAL	{
	$$ = (PostExp*) _tsmalloc(sizeof(PostExp));
	$$->type = 6;
	$$->comp.strVal = $1;
	printf("String Liberal: %s.\n", $$->comp.strVal->String);
	}
	;

argument_expression_list
	: assignment_expression	{
	$$ = (ArgExpList*)_tsmalloc(sizeof(ArgExpList)); 
	$$->type = 1;
	$$->comp.assignExp = $1;
	}
	| argument_expression_list ',' assignment_expression	{
	$$ = (ArgExpList*)_tsmalloc(sizeof(ArgExpList)); 
	$$->type = 2;
	$$->comp.mulArgList.assignExp = $3;
	$$->comp.mulArgList.argList = $1;
	}
	;
unary_expression
	: postfix_expression	{
	$$ = (UnaryExp*) _tsmalloc(sizeof(UnaryExp));
	$$->type = 1;
	$$->comp.postExp = $1;
	}
	| '!' unary_expression	{
	$$ = (UnaryExp*) _tsmalloc(sizeof(UnaryExp));
	$$->type = 2;
	$$->comp.unaryExp = $2;
	}

multiplicative_expression
	: unary_expression	{
	$$ = (MulExp*) _tsmalloc(sizeof(MulExp));
	$$->type = 1;
	$$->comp.unaryExp = $1;
	}
	| multiplicative_expression '*' postfix_expression	{
	$$ = (MulExp*) _tsmalloc(sizeof(MulExp));
	$$->type = 2;
	$$->comp.caltor.op = 1;
	$$->comp.caltor.mulExp = $1;
	$$->comp.caltor.postExp = $3;
	}
	| multiplicative_expression '/' postfix_expression	{
	$$ = (MulExp*) _tsmalloc(sizeof(MulExp));
	$$->type = 2;
	$$->comp.caltor.op = 2;
	$$->comp.caltor.mulExp = $1;
	$$->comp.caltor.postExp = $3;
	}
	| multiplicative_expression '%' postfix_expression	{
	$$ = (MulExp*) _tsmalloc(sizeof(MulExp));
	$$->type = 2;
	$$->comp.caltor.op = 3;
	$$->comp.caltor.mulExp = $1;
	$$->comp.caltor.postExp = $3;
	}
	;

additive_expression
	: multiplicative_expression	{
	$$ = (AddExp*)_tsmalloc(sizeof(AddExp));
	$$->type = 1;
	$$->comp.mulExp = $1;
	}
	| additive_expression '+' multiplicative_expression	{
	$$ = (AddExp*)_tsmalloc(sizeof(AddExp));
	$$->type = 2;
	$$->comp.caltor.op = 1;
	$$->comp.caltor.mulExp = $3;
	$$->comp.caltor.addExp = $1;
	}
	| additive_expression '-' multiplicative_expression	{
	$$ = (AddExp*)_tsmalloc(sizeof(AddExp));
	$$->type = 2;
	$$->comp.caltor.op = 2;
	$$->comp.caltor.mulExp = $3;
	$$->comp.caltor.addExp = $1;
	}
	;

relational_expression
	: additive_expression	{
	$$ = (RelExp*) _tsmalloc(sizeof(RelExp));
	$$->type = 1;
	$$->comp.addExp = $1;
	}
	| relational_expression '<' additive_expression	{
	$$ = (RelExp*) _tsmalloc(sizeof(RelExp));
	$$->type = 2;
	$$->comp.caltor.addExp = $3;
	$$->comp.caltor.relExp = $1;
	$$->comp.caltor.op = 1;
	}
	| relational_expression '>' additive_expression	{
	$$ = (RelExp*) _tsmalloc(sizeof(RelExp));
	$$->type = 2;
	$$->comp.caltor.addExp = $3;
	$$->comp.caltor.relExp = $1;
	$$->comp.caltor.op = 2;
	}
	| relational_expression LE_OP additive_expression	{
	$$ = (RelExp*) _tsmalloc(sizeof(RelExp));
	$$->type = 2;
	$$->comp.caltor.addExp = $3;
	$$->comp.caltor.relExp = $1;
	$$->comp.caltor.op = 3;
	}
	| relational_expression GE_OP additive_expression	{
	$$ = (RelExp*) _tsmalloc(sizeof(RelExp));
	$$->type = 2;
	$$->comp.caltor.addExp = $3;
	$$->comp.caltor.relExp = $1;
	$$->comp.caltor.op = 4;
	}
	;

equality_expression
	: relational_expression	{
	$$ = (EqExp*) _tsmalloc(sizeof(EqExp));
	$$->type = 1;
	$$->comp.relExp = $1;
	}
	| equality_expression EQ_OP relational_expression	{
	$$ = (EqExp*) _tsmalloc(sizeof(EqExp));
	$$->type = 2;
	$$->comp.caltor.relExp = $3;
	$$->comp.caltor.eqExp = $1;
	$$->comp.caltor.op = 1;
	}
	| equality_expression NE_OP relational_expression	{
	$$ = (EqExp*) _tsmalloc(sizeof(EqExp));
	$$->type = 2;
	$$->comp.caltor.relExp = $3;
	$$->comp.caltor.eqExp = $1;
	$$->comp.caltor.op = 3;
	}
	;

logical_and_expression
	: equality_expression	{
	$$ = (LogAndExp*) _tsmalloc(sizeof(LogAndExp));
	$$->type = 1;
	$$->comp.eqExp = $1;
	}
	| logical_and_expression AND_OP equality_expression	{
	$$ = (LogAndExp*) _tsmalloc(sizeof(LogAndExp));
	$$->type = 2;
	$$->comp.caltor.logExp = $1;
	$$->comp.caltor.eqExp = $3;
	}
	;

logical_or_expression
	: logical_and_expression	{
	$$ = (LogOrExp*) _tsmalloc(sizeof(LogOrExp));
	$$->type = 1;
	$$->comp.andExp = $1;
	}
	| logical_or_expression OR_OP logical_and_expression	{
	$$ = (LogOrExp*) _tsmalloc(sizeof(LogOrExp));
	$$->type = 2;
	$$->comp.caltor.andExp = $3;
	$$->comp.caltor.orExp = $1;
	}
	;

conditional_expression
	: logical_or_expression	{
	$$ = (CondExp*) _tsmalloc(sizeof(CondExp));
	$$->type = 1;
	$$->comp.orExp = $1;
	}
	| logical_or_expression '?' expression ':' conditional_expression	{
	$$ = (CondExp*) _tsmalloc(sizeof(CondExp));
	$$->type = 2;
	$$->comp.mulCaltor.orExp = $1;
	$$->comp.mulCaltor.exp = $3;
	$$->comp.mulCaltor.condExp = $5;
	}
	;

assignment_expression
	: conditional_expression	{
	$$ = (AssignExp*) _tsmalloc(sizeof(AssignExp));
	$$->type = 1;
	$$->comp.condExp = $1;
	}
	| VARIANT assignment_operator assignment_expression	{
	$$ = (AssignExp*) _tsmalloc(sizeof(AssignExp));
	$$->type = 2;
	$$->comp.exp.strVal = $1;
	$$->comp.exp.op = $2;
	$$->comp.exp.assignExp = $3;
	}
	;

assignment_operator
	: '='	{
	$$ = 1;
	}
	| MUL_ASSIGN	{
	$$ = 2;
	}
	| DIV_ASSIGN	{
	$$ = 3;
	}
	| MOD_ASSIGN	{
	$$ = 4;
	}
	| ADD_ASSIGN	{
	$$ = 5;
	}
	| SUB_ASSIGN	{
	$$ = 6;
	}
	;

expression
	: assignment_expression	{
	$$ = (Exp*) _tsmalloc(sizeof(Exp));
	$$->type = 1;
	$$->comp.assignExp = $1;
	}
	| expression ',' assignment_expression	{
	$$ = (Exp*) _tsmalloc(sizeof(Exp));
	$$->type = 2;
	$$->comp.mulExp.assignExp = $3;
	$$->comp.mulExp.exp = $1;
	}
	;

identifier_list
	:VARIANT	{
	$$ = (IDList*) _tsmalloc(sizeof(IDList));
	$$->type = 1;
	$$->comp.id = $1;
	}
	| identifier_list ',' VARIANT	{
	IDList* temp;
	$$ = (IDList*) _tsmalloc(sizeof(IDList));
	$$->type = 2;
	$$->comp.mulExp.id = $3;
	$$->comp.mulExp.ilist = $1;
	printf("ID List:\n");
	temp = $$;
	while(temp->type != 1){
		printf("%s\n", temp->comp.mulExp.id->String);
		temp = temp->comp.mulExp.ilist;
	}
	printf("%s\n", temp->comp.id->String);
	}
	;

statement
	:  compound_statement	{
	$$ = (Stmt*) _tsmalloc(sizeof(Stmt));
	$$->type = 1;
	$$->comp.compStmt = $1;
	}
	| expression_statement	{
	$$ = (Stmt*) _tsmalloc(sizeof(Stmt));
	$$->type = 2;
	$$->comp.expStmt = $1;
	}
	| selection_statement	{
	$$ = (Stmt*) _tsmalloc(sizeof(Stmt));
	$$->type = 3;
	$$->comp.selStmt = $1;
	}
	| iteration_statement	{
	$$ = (Stmt*) _tsmalloc(sizeof(Stmt));
	$$->type = 4;
	$$->comp.itorStmt = $1;
	}
	;

compound_statement
	: '{' '}'	{
	$$ = (CompStmt*) _tsmalloc(sizeof(CompStmt));
	$$->type = 1;
	}
	| '{' statement_list '}'	{
	$$ = (CompStmt*) _tsmalloc(sizeof(CompStmt));
	$$->type = 2;
	$$->stmtList = $2;
	}
	;

statement_list
	: statement	{
	$$ = (StmtList*) _tsmalloc(sizeof(StmtList));
	$$->type = 1;
	$$->comp.stmt = $1;
	}
	| statement_list statement	{
	$$ = (StmtList*) _tsmalloc(sizeof(StmtList));
	$$->type = 2;
	$$->comp.list.stmt = $2;
	$$->comp.list.slist = $1;
	}
	;

expression_statement
	: ';'	{
	$$ = (ExpStmt*) _tsmalloc(sizeof(ExpStmt));
	$$->type = 1;
	}
	| expression ';'	{
	$$ = (ExpStmt*) _tsmalloc(sizeof(ExpStmt));
	$$->type = 2;
	$$->exp = $1;
	}
	;

selection_statement
	: IF '(' expression ')' statement %prec IFX	{
	$$ = (SelStmt*) _tsmalloc(sizeof(SelStmt));
	$$->type = 1;
	$$->exp = $3;
	$$->ifStmt = $5;
	}
	| IF '(' expression ')' statement ELSE statement	{
	$$ = (SelStmt*) _tsmalloc(sizeof(SelStmt));
	$$->type = 1;
	$$->exp = $3;
	$$->ifStmt = $5;
	$$->elStmt = $7;
	}
	;

iteration_statement
	: WHILE '(' expression ')' statement	{
	$$ = (ItorStmt*) _tsmalloc(sizeof(ItorStmt));
	$$->type = 1;
	$$->comp.wstmt.exp = $3;
	$$->comp.wstmt.stmt = $5;
	}
	| DO statement WHILE '(' expression ')' ';'{
	$$ = (ItorStmt*) _tsmalloc(sizeof(ItorStmt));
	$$->type = 2;
	$$->comp.wstmt.exp = $5;
	$$->comp.wstmt.stmt = $2;
	}
	| FOR '(' expression_statement expression_statement expression ')' statement	{
	$$ = (ItorStmt*) _tsmalloc(sizeof(ItorStmt));
	$$->type = 3;
	$$->comp.fstmt.expStmt1 = $3;
	$$->comp.fstmt.expStmt2 = $4;
	$$->comp.fstmt.exp = $5;
	$$->comp.fstmt.stmt = $7;
	}
	;

translation_unit
	: external_declaration	{
	$$ = (TransUnit*) _tsmalloc(sizeof(TransUnit));
	$$->type = 1;
	$$->comp.extDecl = $1;
	}
	| translation_unit external_declaration	{
	$$ = (TransUnit*) _tsmalloc(sizeof(TransUnit));
	$$->type = 1;
	$$->comp.mulUnit.extDecl = $2;
	$$->comp.mulUnit.transUnit = $1;
	}
	;

external_declaration
	: compound_statement	{
	$$ = (ExtDecl*) _tsmalloc(sizeof(ExtDecl));
	$$->type = 1;
	$$->comp.compStmt = $1;
	}
	| function_definition	{
	$$ = (ExtDecl*) _tsmalloc(sizeof(ExtDecl));
	$$->type = 2;
	$$->comp.funDef = $1;
	}

function_definition
	:FUNCTION IDENTIFIER '(' identifier_list ')' compound_statement	{
	$$ = (FunDef*) _tsmalloc(sizeof(FunDef));
	$$->name = $2;
	$$->ilist = $4;
	$$->compStmt = $6;
	printf("Found function: %s.\n", $2->String);
	}
	| FUNCTION IDENTIFIER '(' ')' compound_statement	{
	$$ = (FunDef*) _tsmalloc(sizeof(FunDef));
	$$->name = $2;
	$$->ilist = NULL;
	$$->compStmt = $5;
	printf("Found function: %s.\n", $2->String);
	}
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

void echo(const char* grouping, const char* terms){
	printf("grouping found: %s => %s.\n", grouping, terms);
}

