#include "tsstr.h"

void test_tsstr(){
	TSStr* str;
	str = StrCreate();
	StrAppendS(str, "Hello, world!");
	StrReplaceS(str, "orl", "Andy Chen");
	printf("%s", str->String);
}