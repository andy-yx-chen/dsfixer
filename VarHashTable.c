#include "tsee.h"
#include "tsstr.h"

void FreeList(list_entry* head){
	list_entry* entry;
	entry = head->next;
	while(entry != head){
		EEListItem *item = contain_record(entry, EEListItem, list);
		remove(entry);
		(*item->finalizer)((void*)item->value);
		_tsfree(item);
		entry = head->next;
	}
}

_tsulong varHash(void* str){
	return StrHash((const TSStr*) str, HASH_TABLE_BITS);
}


void InitEEVarTable(EEVarTable* table){
	int i = 0;
	table->hash = &varHash;
	while(i < HASH_TABLE_SIZE){
		init_list(&table->table[i]);
		++i;
	}
}

EEVar* FindVarInTable(EEVarTable* table, const _tsstr name)
/**
	Retrieve a EEVar object from the specified in hash table EEVarTable object with name specified.
	If any can be found, return the EEVar pointer
	else return NULL
*/
{
	TSStr* str;
	EEVar* result = NULL;
	list_entry *list,*entry;
	str = StrCreate();
	StrAppendS(str, name);
	list = &table->table[table->hash(str)];
	StrDestroy(str);
	for_each(list, entry){
		if(! _tsstrcmp(contain_record(entry, EEVar, vlist)->name, name)){
			result = contain_record(entry, EEVar, vlist);
			break;
		}
	}
	return result;
}

void AddVarToTable(EEVarTable* table, EEVar* var){
	TSStr* str;
	list_entry *list;
	str = StrCreate();
	StrAppendS(str, var->name);
	list = &table->table[table->hash(str)];
	insert_before(list, &var->vlist);
	StrDestroy(str);
}


void RemoveVarFromTable(EEVarTable* table, const _tsstr name){
	TSStr* str;
	list_entry *list, *entry;
	EEVar* var;
	str = StrCreate();
	StrAppendS(str, name);
	list = &table->table[table->hash(str)];
	StrDestroy(str);
	for_each(list, entry){
		if( !_tsstrcmp(contain_record(entry, EEVar, vlist)->name, name) ) break;
	}
	if( entry != list ){
		remove(entry);
		var = contain_record(entry, EEVar, vlist);
		/*we need to free the space owned by this entry and its value*/
		FreeEEObject(var->value.type, (void*)var->value.value);

		_tsfree(var);/*finally, free the var object;*/
	}
}

void DeleteVarList(list_entry* head){
	list_entry* entry;
	entry = head->next;
	while(entry != head){
		EEVar* var = contain_record(entry, EEVar, vlist);
		remove(entry);
		entry = entry->next;
		/*we need to free the space owned by this entry and its value*/
		FreeEEObject(var->value.type, var->value.value);

		_tsfree(var);/*finally, free the var object;*/
	}
	init_list(head);
}

void DestroyVarTable(EEVarTable* table){
	int i = 0;
	for(; i < HASH_TABLE_SIZE; ++i){
		DeleteVarList(&table->table[i]);
	}
}

void ResetVarTable(EEVarTable* table){
	int i = 0;
	for(; i < HASH_TABLE_SIZE; ++i){
		list_entry* entry;
		list_entry* head = &table->table[i];
		entry = head->next;
		while(entry != head){
			EEVar* var = contain_record(entry, EEVar, vlist);
			var->value.value = 0;
			var->value.type = 0;
			entry = entry->next;
		}
		init_list(head);
	}
}