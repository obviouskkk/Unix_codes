#include <stdio.h>
#include <dlfcn.h>

void * dll = NULL;

typedef void (*load)();
load dl_load;
int main(int argc, const char* argv[])
{
	dll =  dlopen("./libload.so", RTLD_NOW);
	if (!dlib) {
		printf("dlopen error: %s\n", dlerror());
	}
	dl_load = (load)dlsym(dlib, "handle_reload");
	if (!dl_load)
		printf("dlopen error: %s\n", dlerror());
	dl_load();
	return 0;
}

