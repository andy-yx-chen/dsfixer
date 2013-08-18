#ifndef __TSEE_H__
#define __TSEE_H__
#include "ts.h"
#include "tsstr.h"
#include "tsfx.h"

#define HASH_TABLE_SIZE 256
#define HASH_TABLE_BITS 8
#ifdef _WIN64
#define DATA_WIDTH 8
#else
#define DATA_WIDTH 4
#endif

#define object_hash(object) ((_tsulong)object * 0x9e370001UL) >> (32 - HASH_TABLE_BITS)
#define trace_obj(val) if((val)->type == String || (val)->type == List) RegisterObject((void*)(val)->value)
#define try_free(val) if(((val)->type == String || (val)->type == List) && RemoveObject((void*)(val)->value) == 0) FreeEEObject((val)->type, (void*) (val)->value)
#define decl_inst(i) extern void i(EEVal **, int )
#define impl_inst(i) void i(EEVal** regs, int regc)
#define ip_goto(entry) g_context->ip = contain_record(entry, EEInst, list)
#define ExecNextInst(){\
			list_entry *entry;\
			entry = g_context->ip->list.next;\
			g_context->ip = contain_record(entry, EEInst, list);\
		}

#if __cplusplus
extern "C"{
#endif
	typedef _tsulong (*HashFunctor)(void*);
	typedef void (*VoidFunctor)(void*);
	typedef enum _EEValType{
		String = 0x1001,
		Number,
		Char,
		Functor,
		Instruction,
		List,
		Ret = 0x10000
	} EEValType;

	typedef struct _EEVal{
		_tsint type; /*Value type*/
		_tspvoid value; /*Value, can be a pointer or a value*/
	} EEVal;

	typedef struct _EEListItem{
		list_entry list;
		_tsulong value;
		VoidFunctor finalizer;
	}EEListItem;
	
	typedef void (*IFunctor) (EEVal**, int); /*Instruction prototype*/

	typedef struct _EEInst{
		list_entry list; /*Instruction list*/
		IFunctor func; /*functor for this instruction*/
		EEVal** regv; /*Regs used by the functor*/
		int regc; /*Reg count*/
	} EEInst;
	
	typedef struct _EEVar{
		list_entry vlist; /*Variable list*/
		_tsstr name; /*Variable Name*/
		EEVal value; /*Variable Value*/
	} EEVar;

	typedef struct _EEVarTable{
		list_entry table[HASH_TABLE_SIZE]; /*Hash Table*/
		HashFunctor hash; /*Hash function*/
	}EEVarTable;

	typedef struct _EEConst{
		list_entry list; /*Constant List*/
		EEVal value; /*Constant Value*/
	} EEConst;

	typedef struct _EEFunction{
		list_entry ilist; /*Instruction list*/
		list_entry args; /*Argument List*/
		EEVarTable vars; /*Variables defined in this function*/
		list_entry flist; /*Function List*/
	} EEFunction;

	/*Object table entry*/
	typedef struct _EEObjectHashEntry{
		list_entry hlist; /*object list*/
		void* object; /*this object*/
		int ref; /*reference count*/
	}EEObjectHashEntry;

	typedef struct _EEProgram{
		EEFunction global; /*Global function*/
		EEVarTable functions; /*Function table*/
		list_entry constants; /*Constant list*/
		EEInst* entry; /*Entry point*/
	} EEProgram;
	
	/*Call frame for Execution Engine*/
	typedef struct _EECallFrame{
		single_list list;
		EEInst* retAddr;
		EEFunction* function;
	}EECallFrame;

	typedef struct _EEContext{
		EEInst* ip; /*Instruction Pointer*/
		list_entry stack; /*Stack*/
		EEVal ret; /*Last return value*/
		EEFunction* currentFunc; /*Current executing function*/
		EEProgram* program; /*Program object*/
		EECallFrame* callstack;
		_tschar br; /*branch*/
		list_entry objectTable[HASH_TABLE_SIZE]; /*Object table, haven't used in current version*/
	} EEContext;

	/*Stack entry for Execution Engine*/
	typedef struct _EEStackEntry{
		list_entry list; /*Stack List*/
		EEVal* value; /*Stack Value*/
	} EEStackEntry;


	typedef struct _EEInstSet{
		IFunctor lod;
		IFunctor sto;
		IFunctor add;
		IFunctor sub;
		IFunctor div;
		IFunctor mul;
		IFunctor mod;
		IFunctor exec;
		IFunctor call;
		IFunctor lt;
		IFunctor gt;
		IFunctor eq;
		IFunctor not;
		IFunctor ret;
		IFunctor jmp;
		IFunctor jt;
	}EEInstSet;
	//Execute Engine Globals
	EEInstSet* g_instset;
	EEContext* g_context;
	//Functions for EE
	void InitEEContext();
	void FreeEEContext();
	void InitInstSet();
	void FreeInitSet();
	void RegisterObject(_tspvoid);
	int RemoveObject(_tspvoid);
	void FreeEEObject(_tsint, _tspvoid);
	void EEErr(const _tsstr);
	void EERun(EEProgram*);
	//Functions for EEVarTable
	void InitEEVarTable(EEVarTable*);
	EEVar* FindVarInTable(EEVarTable*, const _tsstr);
	void AddVarToTable(EEVarTable*, EEVar*);
	void RemoveVarFromTable(EEVarTable*, const _tsstr);
	void DestroyVarTable(EEVarTable*);
	void ResetVarTable(EEVarTable* table);
	EEVal* TranslateFxRet(pfx_ret ret);
#if __cplusplus
};
#endif

#endif //__TSEE_H__