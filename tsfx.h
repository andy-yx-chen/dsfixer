#ifndef _TSFX_H_
#define _TSFX_H_

#ifndef null
#define null 0
#endif

#if __cplusplus
extern "C"{
#endif
	typedef enum _fx_ret_type{
		number = 1, 
		string, /*a NULL terminated string, only Multibyte string is supported*/
		list /*a buffer contains an array of pointers, the first pointer is the array length, others are pfx_ret*/
	}fx_ret_type;
	/*the return object from TSFX*/
	typedef struct _fx_ret{
		int type;
		void* buffer;
	}fx_ret, *pfx_ret;

	/*call the component API*/
	pfx_ret call(const char* comp, const char* func, int argc, void* argv);

	/*free the return value */
	void free_ret_obj(pfx_ret ret);

	/*get a new ret object*/
	pfx_ret malloc_ret_obj();

#if __cplusplus
}
#endif
#endif //_TSFX_H_