/* ***********************************************************************

  > File Name: reload.hpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 14 Jan 2018 10:45:08 PM CST

 ********************************************************************** */

#ifndef __RELOAD_HPP__
#define __RELOAD_HPP__


#include "common.hpp"
#include <stdio.h>
#include <dlfcn.h> 
#include <stdio.h>
#include <unistd.h>

void *dlib = NULL;

base_t dl_base;

class sess
{
public:
	void doall(){
		/*
		dlib =  dlopen("./libtest.so", RTLD_NOW);
		if (!dlib) {
			printf("dlopen error: %s\n", dlerror());
		}
		dl_base = (base_t)dlsym(dlib, "ret_class");
		if (!dl_base)
			printf("dlopen error: %s\n", dlerror());
		dl_base()->add(1, 2);

		sleep(50);
		if (dlib != NULL)
			dlclose(dlib);
		dlib = NULL;

		dlib =  dlopen("./libtest.so", RTLD_NOW);
		if (!dlib) {
			printf("dlopen error: %s\n", dlerror());
		}
		dl_base = (base_t)dlsym(dlib, "ret_class");
		if (!dl_base)
			printf("dlopen error: %s\n", dlerror());

		dl_base()->add(1, 2);

		dlclose(dlib);
		*/
		printf("hello world\n");
	}

	static sess * get_sess(){
		static sess* ses = new sess();
		return ses;
	}
public:
	static sess* ses;
	
};



#endif //__RELOAD_HPP__
