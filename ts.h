#ifndef __AUTO_TS_H__
#define __AUTO_TS_H__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*define null to 0*/
#ifndef null
#define null 0
#define DbgTrace(MSG) printf MSG
#endif

#define push(head, entry)\
	(entry)->next = (head)->next;\
	(head)->next->prev = entry;\
	(entry)->prev = (head);\
	(head)->next = (entry)
#define pop(head, entry)\
	(entry) = (head)->next;\
	(head)->next = (entry)->next;\
	(entry)->next->prev = (head)
#define top(head) (head)->next
#define init_list(head)\
	(head)->next = (head);\
	(head)->prev = (head)
#define is_empty(head)\
	((head)->next == (head) && (head)->prev == (head))
#define contain_record(entry, type, field)\
	((type*)((char*)(entry) - (char*)(&((type*)0)->field)))
#define for_each(head, entry)\
	for(entry = (head)->next; entry != (head); entry = (entry)->next)
#define insert_before(current, entry)\
	(entry)->next = current;\
	(entry)->prev = (current)->prev;\
	(current)->prev->next = entry;\
	(current)->prev = entry
#define insert_after(current, entry)\
	(entry)->prev = current;\
	(entry)->next = (current)->next;\
	(current)->next->prev = entry;\
	(current)->next = entry
#define remove(entry)\
	(entry)->next->prev = (entry)->prev;\
	(entry)->prev->next = (entry)->next

#define init_single_list(head)\
	(head)->next = (head)
#define single_list_push(head, entry)\
	(entry)->next = (head)->next;\
	(head)->next = entry
#define single_list_pop(head, entry)\
	entry = (head)->next;\
	(head)->next = (entry)->next

#define _tsmalloc malloc
#define _tsfree free
#define _tsstrcmp strcmp
#define _tsstrcpy strcpy_s

#if __cplusplus
extern "C"{
#endif
	typedef char* _tsstr;
	typedef unsigned long _tsulong;
	typedef unsigned int _tsuint;
	typedef unsigned char _tsuchar;
	typedef unsigned short _tsushort;
	typedef char _tschar;
	typedef int _tsint;
	typedef long _tslong;
	typedef short _tsshort;
	typedef void* _tspvoid;

	struct _list_entry{
		struct _list_entry* prev;
		struct _list_entry* next;
	};

	typedef struct _list_entry list_entry;

	typedef struct _single_list{
		struct _single_list* next;
	} single_list;

#if __cplusplus
};
#endif
#endif //__AUTO_TS_H__