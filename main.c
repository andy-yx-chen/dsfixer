#include <stdlib.h>
#include <stdio.h>
#include "tsc.h"
#include "tsee.h"
#include "tsstr.h"

void yyparse(EEProgram*);
extern FILE* yyin;
extern void test_var_table();
extern void test_tsstr();
extern void test_obj_mgr();
extern void test_tsc();

int main(int argc, char* argv[])
{
	EEProgram program;
	fopen_s(&yyin, argv[1], "r");
	yyparse(&program);
	fclose(yyin);
	system("pause");
	return 0;
}