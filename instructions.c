#include "tsee.h"
#include "tsstr.h"

#define inst_assert(cond)	if( !(cond) ) EEErr("Instruction error.\n")
#define assign_val(dest, src)	(dest)->type = (src)->type;\
	(dest)->value = (src)->value;

/*
 * Loads the value in reg[0] into stack
*/
impl_inst(ee_load){
	EEStackEntry *entry;
	inst_assert(regc == 1);
	entry = (EEStackEntry*) _tsmalloc(sizeof(EEStackEntry));
	DbgTrace(("create stack entry @ %x\n", (_tsulong)entry));
	assign_val(entry->value, *regs);
	push(&g_context->stack, &entry->list);
	DbgTrace(("push item %x\n", entry->value->value));
	ExecNextInst();
}

/*
 * Stores the value item on the top of the stack into the reg[0] (if regc == 1) and pops it.
*/
impl_inst(ee_store){
	list_entry *entry;
	EEStackEntry *stackEntry;
	pop(&g_context->stack, entry);
	stackEntry = contain_record(entry, EEStackEntry, list);
	if(regc >0 ){
		assign_val(*regs, stackEntry->value);
	}

	if((stackEntry->value->type & Ret) && !regc){
		DbgTrace(("free returned object %x\n", stackEntry->value->value));
		FreeEEObject(stackEntry->value->type, (void*)stackEntry->value->value);
	}
	_tsfree(stackEntry);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)stackEntry));
	ExecNextInst();
}

/*
 * Pop the source operator from the stack, add the value into the top item of the stack
*/
impl_inst(ee_add){
	list_entry *entry;
	EEStackEntry *op1, *op2;
	pop(&g_context->stack, entry);
	op2 = contain_record(entry, EEStackEntry, list);
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert( (op2->value->type == String || op2->value->type == Number)\
		&& (op1->value->type == String || op1->value->type == Number));
	if(op1->value->type == op2->value->type){
		if(op1->value->type == String){
			TSStr *str1, *str2;
			str1 = (TSStr*)op1->value->value;
			str2 = (TSStr*)op2->value->value;
			StrAppendS(str1, str2->String);
		}else{
			op1->value->value = (void*)(((_tsulong)op1->value->value) + ((_tsulong)op2->value->value));
		}
	}else{
		_tsstr numStr;
		numStr = (_tsstr)_tsmalloc((sizeof(long) * 2 + 3) * sizeof(_tschar));
		if(op1->value->type == Number){
			TSStr* str;
			str = StrCreate();
			sprintf_s(numStr, (sizeof(long) * 2 + 3) * sizeof(_tschar), "0x%0x", op1->value->value);
			StrAppendS(str, numStr);
			StrAppendS(str, ((TSStr*)op2->value->value)->String);
			op1->value->type = String;
			op1->value->value = (void*)str;
		}else{
			sprintf_s(numStr, (sizeof(long) * 2 + 3) * sizeof(_tschar), "0x%0x", op2->value->value);
			StrAppendS((TSStr*)op1->value->value, numStr);
		}
		_tsfree(numStr);
	}

	if(op2->value->type & Ret){
		DbgTrace(("free returned object %x\n", op2->value->value));
		FreeEEObject(op2->value->type, (void*)op2->value->value);
	}
	
	_tsfree(op2);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)op2));
	ExecNextInst();
}

/*
 * Pop the source operator from the stack, substract the value from the top item of the stack
 * Only Number values are supported
*/
impl_inst(ee_sub){
	list_entry *entry;
	EEStackEntry *op1, *op2;
	pop(&g_context->stack, entry);
	op2 = contain_record(entry, EEStackEntry, list);
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert(op1->value->type == Number && op2->value->type == Number);
	op1->value->value = (void*)(((_tsulong)op1->value->value) - ((_tsulong) op2->value->value));
	
	if(op2->value->type & Ret){
		DbgTrace(("free returned object %x\n", op2->value->value));
		FreeEEObject(op2->value->type, (void*)op2->value->value);
	}
	_tsfree(op2);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)op2));
	ExecNextInst();
}

/*
 * Pop the source operator from the stack, multiplies the value to the top item of the stack
 * Only Number values are supported
*/
impl_inst(ee_mul){
	list_entry *entry;
	EEStackEntry *op1, *op2;
	pop(&g_context->stack, entry);
	op2 = contain_record(entry, EEStackEntry, list);
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert(op1->value->type == Number && op2->value->type == Number);
	op1->value->value = (void*)(((_tsulong)op1->value->value) * ((_tsulong) op2->value->value));
	
	if(op2->value->type & Ret){
		DbgTrace(("free returned object %x\n", op2->value->value));
		FreeEEObject(op2->value->type, (void*)op2->value->value);
	}
	_tsfree(op2);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)op2));
	ExecNextInst();
}

/*
 * Pop the source operator from the stack, divides the top item of the stack by the popped value
 * Only Number values are supported
*/
impl_inst(ee_div){
	list_entry *entry;
	EEStackEntry *op1, *op2;
	pop(&g_context->stack, entry);
	op2 = contain_record(entry, EEStackEntry, list);
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert(op1->value->type == Number && op2->value->type == Number);
	op1->value->value = (void*)(((_tsulong)op1->value->value) / ((_tsulong) op2->value->value));
	
	if(op2->value->type & Ret){
		DbgTrace(("free returned object %x\n", op2->value->value));
		FreeEEObject(op2->value->type, (void*)op2->value->value);
	}
	_tsfree(op2);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)op2));
	ExecNextInst();
}

/*
 * Pop the source operator from the stack, mods the top item of the stack by the popped value
 * Only Number values are supported
*/
impl_inst(ee_mod){
	list_entry *entry;
	EEStackEntry *op1, *op2;
	pop(&g_context->stack, entry);
	op2 = contain_record(entry, EEStackEntry, list);
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert(op1->value->type == Number && op2->value->type == Number);
	op1->value->value = (void*)(((_tsulong)op1->value->value) % ((_tsulong) op2->value->value));
	
	if(op2->value->type & Ret){
		DbgTrace(("free returned object %x\n", op2->value->value));
		FreeEEObject(op2->value->type, (void*)op2->value->value);
	}
	_tsfree(op2);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)op2));
	ExecNextInst();
}

/*
 * The entry point to call to Troubleshooting Framework (TSFX)
 * Pops the function name and then pops the component name from the stack.
 * Retrieves argument length from the reg[0] and then pops the specified amount value items
 *  from stack as parameters for the target function.
 * the argument length is stored in regs[0], this instruction frees the object after used.
*/
impl_inst(ee_exec){
	_tsint argc;
	_tspvoid* argvs;
	_tschar *comp, *func;
	EEStackEntry* stackItem;
	list_entry *entry;
	EEVal* ret;

	/*get component name*/
	pop(&g_context->stack, entry);
	stackItem = contain_record(entry, EEStackEntry, list);
	comp = ((TSStr*)stackItem->value->value)->String;
	_tsfree(stackItem);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)stackItem));

	/*get function name*/
	pop(&g_context->stack, entry);
	stackItem = contain_record(entry, EEStackEntry, list);
	func = ((TSStr*)stackItem->value->value)->String;
	_tsfree(stackItem);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)stackItem));

	/*get argument count*/
	argc = (_tsint)regs[0]->value;
	/*free the argument count object*/
	_tsfree(regs[0]);

	/*get all reguments*/
	argvs = (_tspvoid*)_tsmalloc(sizeof(_tslong) * argc);
	while(argc){
		pop(&g_context->stack, entry);
		stackItem = contain_record(entry, EEStackEntry, list);
		argvs[argc--] = stackItem->value->value;
		_tsfree(stackItem);
		DbgTrace(("free stack entry @ %x\n", (_tsulong)stackItem));
	}

	/*now, call tsfx to execute the function*/
	ret = TranslateFxRet(call(comp, func, argc, argvs));
	stackItem = (EEStackEntry*) _tsmalloc(sizeof(EEStackEntry));
	stackItem->value = ret;
	push(&g_context->stack, &stackItem->list);
	/*We need to keep track of the return object*/
	if(!ret){
		DbgTrace(("return object %x\n", ret->value));
		ret->type = (ret->type | Ret);
	}
	/*free the argvs*/
	_tsfree(argvs);
	ExecNextInst();
}

/*
 * Pushes the return address and current function into callstack of execution context
 * Pops the function address from the top of the stack,
 * after that the top of the stack is the count of the arguments
*/
impl_inst(ee_call){
	EEStackEntry* stackEntry;
	list_entry *entry;
	EECallFrame* frame;

	pop(&g_context->stack, entry);
	stackEntry = contain_record(entry, EEStackEntry, list);
	frame = (EECallFrame*) _tsmalloc(sizeof(EECallFrame));
	frame->function = (EEFunction*)stackEntry->value->value;
	frame->retAddr = contain_record(g_context->ip->list.next, EEInst, list);
	frame->list.next = &g_context->callstack->list;
	g_context->currentFunc = frame->function; //update the current function pointer
	g_context->ip = contain_record(&frame->function->ilist.next, EEInst, list); //reset the ip to the new entry point
}

/**
 * Pops the return address from callstack and reset it to ip
*/
impl_inst(ee_ret){
	EECallFrame* frame;
	single_list* entry;

	inst_assert(g_context->callstack->list.next != null);

	//reset all variable for the current fuction
	ResetVarTable(&g_context->currentFunc->vars);
	//pops the call frame
	entry = g_context->callstack->list.next;
	frame = contain_record(entry, EECallFrame, list);
	g_context->ip = g_context->callstack->retAddr;
	g_context->callstack = frame;
}

/*
 * Compares top two items of the stack, if the second one less than the top one, set second one's value to 1, else set its value to 0
 * the top one will be poped and freed
 * Only Number values are supported
*/
impl_inst(ee_lt){
	list_entry *entry;
	EEStackEntry *op1, *op2;
	pop(&g_context->stack, entry);
	op2 = contain_record(entry, EEStackEntry, list);
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert(op1->value->type == Number && op2->value->type == Number);
	op1->value->value = (void*)(((_tsulong)op1->value->value) < ((_tsulong) op2->value->value) ? 1 : 0);
	
	if(op2->value->type & Ret){
		DbgTrace(("free returned object %x\n", op2->value->value));
		FreeEEObject(op2->value->type, (void*)op2->value->value);
	}
	_tsfree(op2);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)op2));
	ExecNextInst();
}

/*
 * Compares top two items of the stack, if the second one greater than the top one, set second one's value to 1, else set its value to 0
 * the top one will be poped and freed
 * Only Number values are supported
*/
impl_inst(ee_gt){
	list_entry *entry;
	EEStackEntry *op1, *op2;
	pop(&g_context->stack, entry);
	op2 = contain_record(entry, EEStackEntry, list);
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert(op1->value->type == Number && op2->value->type == Number);
	op1->value->value = (void*)(((_tsulong)op1->value->value) > ((_tsulong) op2->value->value) ? 1 : 0);
	
	if(op2->value->type & Ret){
		DbgTrace(("free returned object %x\n", op2->value->value));
		FreeEEObject(op2->value->type, (void*)op2->value->value);
	}
	_tsfree(op2);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)op2));
	ExecNextInst();
}

/**
 * Set the ip to the instrcution specified in the top of the stack 
*/
impl_inst(ee_jmp){
	list_entry* entry;
	EEStackEntry *stackItem;

	pop(&g_context->stack, entry);
	stackItem = contain_record(entry, EEStackEntry, list);
	g_context->ip = contain_record(stackItem->value->value, EEInst, list);
}

/**
 * Set the ip to the instrcution specified in the second item of the stack if the value of the stack top item is not zero
*/
impl_inst(ee_jt){
	list_entry* entry;
	EEStackEntry *stackItem;
	_tspvoid value;

	pop(&g_context->stack, entry);
	stackItem = contain_record(entry, EEStackEntry, list);
	value = stackItem->value->value;
	pop(&g_context->stack, entry);
	stackItem = contain_record(entry, EEStackEntry, list);
	if( value != null){
		g_context->ip = contain_record(stackItem->value->value, EEInst, list);
	}
}

/*
 * Compares top two items of the stack, if the second one equals to the top one, set second one's value to 1, else set its value to 0
 * the top one will be poped and freed
 * Only Number values are supported
*/
impl_inst(ee_eq){
	list_entry *entry;
	EEStackEntry *op1, *op2;
	pop(&g_context->stack, entry);
	op2 = contain_record(entry, EEStackEntry, list);
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert(op1->value->type == Number && op2->value->type == Number);
	op1->value->value = (void*)(((_tsulong)op1->value->value) == ((_tsulong) op2->value->value) ? 1 : 0);
	
	if(op2->value->type & Ret){
		DbgTrace(("free returned object %x\n", op2->value->value));
		FreeEEObject(op2->value->type, (void*)op2->value->value);
	}
	_tsfree(op2);
	DbgTrace(("free stack entry @ %x\n", (_tsulong)op2));
	ExecNextInst();
}

/*
 * if the value for the stack top is 0, set its value to 1, else set its value to 0
 * Only Number values are supported
*/
impl_inst(ee_not){
	EEStackEntry *op1;
	op1 = contain_record(top(&g_context->stack), EEStackEntry, list);
	inst_assert(op1->value->type == Number);
	op1->value->value = (void*)(((_tsulong)op1->value->value) == 0 ? 1 : 0);
	
	ExecNextInst();
}
