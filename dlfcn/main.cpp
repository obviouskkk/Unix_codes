#include <stdio.h>
#include <dlfcn.h>
#include <signal.h>
#include <unistd.h>

#include "common.hpp"

#include "../apue.h"

void * dll = NULL;

typedef void (*load)();

base_t dl_base;

static void  signal_reload(int signo)
{
	dlclose(dll);
	dll = NULL;

	dll =  dlopen("./libtest.so", RTLD_NOW);
	if (!dll) {
		err_exit("dlopen error: %s\n", dlerror());
	}
	dl_base = (base_t)dlsym(dll, "ret_class");
	if (!dl_base)
		err_exit("dlopen error: %s\n", dlerror());
}

int main(int argc, const char* argv[])
{
	dll =  dlopen("./libtest.so", RTLD_NOW);
	if (!dll) {
		err_exit("dlopen error: %s\n", dlerror());
	}
	dl_base = (base_t)dlsym(dll, "ret_class");
	if (!dl_base)
		err_exit("dlopen error: %s\n", dlerror());
	if( signal(SIGUSR1, signal_reload) < 0  )
		err_exit("signal error");
	while(1){
		dl_base()->add(1, 2);
		sleep(1);
	}
	return 0;
}

