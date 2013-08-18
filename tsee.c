#include "tsee.h"


//functions for instruction
decl_inst(ee_store);
decl_inst(ee_load);
decl_inst(ee_add);
decl_inst(ee_sub);
decl_inst(ee_div);
decl_inst(ee_mul);
decl_inst(ee_mod);
decl_inst(ee_call);
decl_inst(ee_exec);
decl_inst(ee_lt);
decl_inst(ee_gt);
decl_inst(ee_eq);
decl_inst(ee_not);
decl_inst(ee_ret);
decl_inst(ee_jmp);
decl_inst(ee_jt);


void InitEEContext(){
	int i = 0;
	g_context = (EEContext*) _tsmalloc(sizeof(EEContext));
	init_list(&g_context->stack);
	g_context->br = 0;
	while(i < HASH_TABLE_SIZE){
		init_list(&g_context->objectTable[i]);
		++i;
	}
	g_context->callstack = (EECallFrame*) _tsmalloc(sizeof(EECallFrame));

	g_context->callstack->list.next = null;
}

void FreeEEContext(){
	_tsfree(g_context->callstack);
	_tsfree(g_context);
}

void EEErr(const _tsstr err){
	fprintf(stderr,err);
	exit(1);
}



void InitInstSet(){
	g_instset = (EEInstSet*) _tsmalloc(sizeof(EEInstSet));
	g_instset->add = &ee_add;
	g_instset->call = &ee_call;
	g_instset->div = &ee_div;
	g_instset->eq = &ee_eq;
	g_instset->exec = &ee_exec;
	g_instset->gt = &ee_gt;
	g_instset->lod = &ee_load;
	g_instset->sto = &ee_store;
	g_instset->lt = &ee_lt;
	g_instset->mod = &ee_mod;
	g_instset->mul = &ee_mul;
	g_instset->not = &ee_not;
	g_instset->ret = &ee_ret;
	g_instset->sub = &ee_sub;
	g_instset->jmp = &ee_jmp;
	g_instset->jt = &ee_jt;
}

void FreeInstSet(){
	_tsfree(g_instset);
}

void EERun( EEProgram* program){
	EEInst* end;
	g_context->program = program;
	g_context->currentFunc = &program->global;
	g_context->ip = program->entry;
	g_context->callstack->function = &program->global;
	g_context->callstack->retAddr = null;
	end = contain_record(&program->global.ilist, EEInst, list);

	while(g_context->ip != end){
		(g_context->ip->func)(g_context->ip->regv, g_context->ip->regc);
	}
}

EEVal* TranslateFxRet(pfx_ret ret){
	EEVal* value;
	value = (EEVal*)_tsmalloc(sizeof(EEVal));
	if(ret == null){
		return null;
	}
	switch(ret->type){
		int szList, i;
	case number:
		value->type = Number;
		value->value = ret->buffer;
		break;
	case string:
		value->type = String;
		value->value = (_tspvoid)StrCreate();
		StrAppendS((TSStr*)value->value, (_tschar*)ret->buffer);
		break;
	case list:
		szList = ((int*)ret->buffer)[0];
		i = 1;
		value->type = List;
		value->value = (_tspvoid)_tsmalloc(sizeof(_tspvoid) * (szList + 1));
		((int*)value->value)[0] = szList;

		for(; i <= szList; ++i){
			((EEVal**)value->value)[i] = TranslateFxRet(((pfx_ret*)ret->buffer)[i]);
		}
		break;
	default:
		/*no other objec type*/
		break;
	}
	return value;
}