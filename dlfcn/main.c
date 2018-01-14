#include <stdio.h>
#include <dlfcn.h>

void * dll = NULL;

typedef void (*load)();
load dl_load;

int main(int argc, const char* argv[])
{
	dll =  dlopen("./libreload.so", RTLD_NOW);
	if (!dll) {
		printf("dlopen error: %s\n", dlerror());
	}
	dl_load = (load)dlsym(dll, "handle_reload");
	if (!dl_load)
		printf("dlopen error: %s\n", dlerror());
	dl_load();
	return 0;
}

