#ifndef __TSSTR_H__
#define __TSSTR_H__

#define _TSSTR_BLOCK_SIZE 32
#define _TSSTR_DELTA_SIZE 16
#define lstrlen strlen

#include "ts.h"

#define TSSTR(str, src) str = StrCreate();\
	StrAppendS(str, src)

#if __cplusplus
extern "C"{
#endif
	/*
		Only ASCII strings are supported in TSL files, 
		if you need to cooperate with UNICODE Windows API, 
		please use mbstowcs_s or MultiByteToWideChar to convert ASCII to UNICODE
	*/
	typedef struct _TSStr{
		_tschar* String;
		int Length;
		int MaxLength;
	} TSStr;

	TSStr* StrCreate();
	void StrAppendC(TSStr*, _tschar);
	void StrDestroy(TSStr*);
	void StrAppendS(TSStr*, const _tschar*);
	void StrInsert(TSStr*, int, const _tschar*);
	int StrSubString(TSStr*, const _tsstr);
	void StrReplace(TSStr*, int, int, const _tschar*);
	void StrReplaceS(TSStr*, const _tsstr , const _tsstr );
	unsigned long StrHash(const TSStr*, unsigned int);
	#if __cplusplus
};
#endif

#endif //__TSSTR_H__