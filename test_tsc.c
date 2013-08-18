#include "tsc.h"

void test_tsc(){
	TSStr* str = StrCreate();
	StrAppendS(str, "0x1001");
	printf("Number: %u.\n", StrToNum(str));
	StrDestroy(str);
}