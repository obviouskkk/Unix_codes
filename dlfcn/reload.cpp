/* ***********************************************************************

  > File Name: reload.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 12 Jan 2018 06:21:12 PM CST

 ********************************************************************** */

#include <dlfcn.h> 
#include <stdio.h>

void * dlib = NULL;

base_t dl_base;
extern "C"{
	void handle_reload(){
		dlib =  dlopen("./libtest.so", RTLD_NOW);
		if (!dlib) {
			printf("dlopen error: %s\n", dlerror());
		}
		dl_base = (base_t)dlsym(dlib, "ret_class");
		if (!dl_base)
			printf("dlopen error: %s\n", dlerror());
		dl_base()->add(1, 2);

		sleep(50);

		dlib =  dlopen("./libtest.so", RTLD_NOW);
		if (!dlib) {
			printf("dlopen error: %s\n", dlerror());
		}
		dl_base = (base_t)dlsym(dlib, "ret_class");
		if (!dl_base)
			printf("dlopen error: %s\n", dlerror());

		dl_base()->add(1, 2);

		dlclose(dlib);
		return 0;
	}
}
