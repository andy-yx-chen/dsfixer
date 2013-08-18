#include "tsee.h"
#include "tsstr.h"

void RegisterObject(void* object){
	EEObjectHashEntry* objEntry;
	list_entry *entry;
	_tsulong hash = object_hash(object);
	if(!is_empty(&g_context->objectTable[hash])){
		for_each(&g_context->objectTable[hash], entry){
			objEntry = contain_record(entry, EEObjectHashEntry, hlist);
			if(objEntry->object == object){
				objEntry->ref += 1;
				return;
			}
		}
	}
	objEntry = (EEObjectHashEntry*) _tsmalloc(sizeof(EEObjectHashEntry));
	objEntry->ref = 1;
	objEntry->object = object;
	insert_before(&g_context->objectTable[hash], &objEntry->hlist);
	
}

/**
** Remove the specific object from hash table
** If the object exists in hash table with ref > 1, --ref, return ref
** If the object exists in has table with ref <= 1, free objEntry, return 0
** If the object doesn't exist, return -1
*/
int RemoveObject(void *object){
	EEObjectHashEntry* objEntry;
	list_entry *entry;
	_tsulong hash = object_hash(object);
	if(!is_empty(&g_context->objectTable[hash])){
		for_each(&g_context->objectTable[hash], entry){
			objEntry = contain_record(entry, EEObjectHashEntry, hlist);
			if(objEntry->object == object){
				if(objEntry->ref > 1){
					objEntry->ref -= 1;
					return objEntry->ref;
				}else{
					remove(entry);
					_tsfree(objEntry);
					return 0;
				}
			}
		}
	}
	return -1;
}

void FreeEEObject(_tsint type, _tspvoid obj){
	switch(type){
	int szList, i;
	case String: 
		StrDestroy((TSStr*)obj); 
		break;
	case List:
		szList = ((int*)obj)[0];
		i = 1;
		for(; i <= szList; ++i){
			EEVal* val = ((EEVal**)obj)[i];
			FreeEEObject(val->type, (void*)val->value);
		}
		break;
	default:
		/*we don't need to free other objec types*/
		break;
	}
}
