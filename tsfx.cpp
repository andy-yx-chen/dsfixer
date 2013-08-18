#include "tsfx.h"
#include <iostream>

pfx_ret call(const char* comp, const char* func, int argc, void* argv){
	using namespace std;
	cout << "Executing " << comp << "." << func << " with " << argc << "arguments" << endl;
	return null;
}

void free_ret_obj(pfx_ret ret){
	delete ret;
}

pfx_ret malloc_ret_obj(){
	return (pfx_ret)operator new(sizeof(fx_ret));
}