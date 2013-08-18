#include "tsee.h"

void test_var_table(){
	EEVarTable table;
	EEVar* var;
	InitEEVarTable(&table);
	var = (EEVar*)_tsmalloc(sizeof(EEVar));
	var->name = "var1";
	AddVarToTable(&table, var);
	var = (EEVar*)_tsmalloc(sizeof(EEVar));
	var->name = "var2";
	AddVarToTable(&table, var);
	var = (EEVar*)_tsmalloc(sizeof(EEVar));
	var->name = "var3";
	AddVarToTable(&table, var);
	var = (EEVar*)_tsmalloc(sizeof(EEVar));
	var->name = "var4";
	AddVarToTable(&table, var);
	var = (EEVar*)_tsmalloc(sizeof(EEVar));
	var->name = "var5";
	AddVarToTable(&table, var);
	var = (EEVar*)_tsmalloc(sizeof(EEVar));
	var->name = "var6";
	AddVarToTable(&table, var);
	var = (EEVar*)_tsmalloc(sizeof(EEVar));
	var->name = "andy";
	AddVarToTable(&table, var);

	var = FindVarInTable(&table, "var4");
	
	RemoveVarFromTable(&table, "andy");
	RemoveVarFromTable(&table, "var1");
	RemoveVarFromTable(&table, "var6");
}