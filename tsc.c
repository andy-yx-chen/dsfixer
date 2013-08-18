#include "tsc.h"

_tsulong StrToNum(TSStr* str){
	_tsulong result = 0UL;
	int i, base = 1, radix = 10;
	if(str->String[0] == '0' && str->String[1] == 'x'){ /* This is a Hex value*/
		StrReplaceS(str, "0x", "");
		radix = 16;
	}
	i = str->Length - 1;
	while(i > -1){
		_tsulong charVal = 0UL;
		if(str->String[i] <= 'F' && str->String[i] >= 'A'){
			charVal = str->String[i] + 10 - 'A';
		}else if(str->String[i] <= 'f' && str->String[i] >= 'a'){
			charVal = str->String[i] + 10 - 'a';
		}else
		{
			charVal = str->String[i] - '0';
		}
		result += (_tsulong)base * charVal;
		base *= radix;
		--i;
	}
	return result;
}