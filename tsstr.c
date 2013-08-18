
#include <stdlib.h>
#include <string.h>

#include "tsstr.h"

TSStr* StrCreate(){
	TSStr* str = (TSStr*) malloc(sizeof(TSStr));
	str->String = (_tsstr) malloc(_TSSTR_BLOCK_SIZE * sizeof(_tschar));
	str->Length = 0;
	str->MaxLength = _TSSTR_BLOCK_SIZE;
	str->String[str->Length] = '\0';
	return str;
}

void StrAppendC(TSStr* str, _tschar ch)
{
	if(str->Length + 1 >= str->MaxLength)
	{
		_tsstr tempStr;
		str->MaxLength += _TSSTR_DELTA_SIZE;
		tempStr = (_tsstr) malloc(str->MaxLength * sizeof(_tschar));
		memset(tempStr, 0, str->MaxLength * sizeof(_tschar));
		memcpy(tempStr, str->String, str->Length * sizeof(_tschar));
		free(str->String);
		str->String = tempStr;
	}
	str->String[str->Length ++] = ch;
	str->String[str->Length] = '\0';
}

void StrDestroy(TSStr* str){
	free(str->String);
	free(str);
}

void StrAppendS(TSStr *str, const _tschar *chars){
	while(*chars)StrAppendC(str, *chars++);
}

void StrInsert(TSStr *str, int index, const _tschar *chars){
	_tsstr tempStr;
	int i = 0, len, j = 0;
	len = lstrlen(chars);
	while(len + str->Length >= str->MaxLength) str->MaxLength += _TSSTR_DELTA_SIZE;
	tempStr = (_tsstr) malloc(str->MaxLength * sizeof(_tschar));
	memset(tempStr, 0, str->MaxLength * sizeof(_tschar));
	if(index < 0) index = 0;
	if(index > 0)
	{
		memcpy(tempStr, str->String, sizeof(_tschar) * index);
	}
	memcpy((void*) (tempStr + index), chars, len * sizeof(_tschar));
	memcpy((void*) (tempStr + index + len), (void*) (str->String + index), (str->Length - index) * sizeof(_tschar));
	
	free(str->String);
	str->String = tempStr;
	str->Length = lstrlen(tempStr);
}

void StrReplace(TSStr *str, int start, int length, const _tschar* chars){
	int i = start;
	while( (i-start) < length && *chars ) str->String[i++] = *chars++;
	if(i - start >= length && *chars) StrInsert(str, i, chars);
	if(i - start < length){
		int k = start + length;
		while( k <= str->Length )str->String[i++] = str->String[k++];
	}
	str->Length = str->Length - length + lstrlen(chars);
}

void __kmp_next(const _tsstr str, int** next){
	int i;
	(*next)[0] = -1;
	for( i = 0; str[i] != '\0'; ++i ){
		(*next)[i + 1] = (*next)[i] + 1;
		while( (*next)[i + 1] > 0 &&
			str[i] != str[(*next)[i + 1] - 1])
			(*next)[i + 1] = (*next)[(*next)[i + 1] - 1] + 1;

	}
}

int StrSubStringIdx(TSStr* str, int index, const _tsstr subStr){
	int pos, i, j = -1;
	int* next = (int*) malloc(( lstrlen(subStr) + 1 ) * sizeof(int));
	__kmp_next(subStr, &next);
	for( i = index; i < str->Length; ++i ){
		int len = lstrlen(subStr);
		pos = 0;
		j = i;
		while(pos < len && j < str->Length){
			if(subStr[pos] == str->String[j]){
				++j, ++pos;
			}else{
				if(!pos) ++j;
				else pos = next[pos - 1] + 1;
			}
		}

		if(pos == len && j - i == len){
			j = i;
			break;
		}
		j = -1;
	}
	free(next);
	return j;
}

int StrSubString(TSStr *str, const _tsstr subStr){
	return StrSubStringIdx(str, 0, subStr);
}

void StrReplaceS(TSStr* str, const _tsstr src, const _tsstr replace){
	int i = 0, j = 0, len = lstrlen(src);
	do{
		j = StrSubStringIdx(str, i, src);
		if( j < 0 ) break;
		StrReplace(str, j, len, replace);
		i += len;
	}while(1);
}

unsigned long StrHash(const TSStr* str, unsigned int bits){
	int i = 0;
	unsigned long hash = 0UL;
	for(; i < str->Length; ++ i){
		hash += (unsigned long)((i + 1) * str->String[i] | (1 << ((i + 1) % 32)));
	}
	hash *= 0x9e370001UL;
	return hash >> (32 -  bits);
}