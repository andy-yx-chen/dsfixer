#include "tsee.h"
#include "tsstr.h"

void test_obj_mgr(){
	register int i = 0;
	TSStr* strings[500];
	InitEEContext();
	while( i < 500 ){
		strings[i] = StrCreate();
		++i;
	}
	i = 0;
	while( i < 500 ){
		RegisterObject(strings[i]);
		++i;
	}
	i = 0;
	while( i < 500 ){
		RegisterObject(strings[i]);
		++i;
	}
	i = 0;
	while( i < 500 ){
		RemoveObject(strings[i]);
		++i;
	}
	i = 0;
	while( i < 500 ){
		RemoveObject(strings[i]);
		++i;
	}
	FreeEEContext();
}