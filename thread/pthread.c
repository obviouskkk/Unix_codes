/* ***********************************************************************

  > File Name: pthread.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 16 Jan 2018 05:18:49 PM CST

 ********************************************************************** */

#include "../apue.h"

#include <pthread.h>

/*
 * int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
 *                    void *(*start_routine) (void *), void *arg);
 *
 */
static void * pthread_echo(void * arg)
{
	printf("pid :%u,tid: %lu, %s, (0x%lx)\n", getpid() ,
		pthread_self(), (char*)arg, (unsigned long )pthread_self() );
	return NULL;
}

int main(int argc, const char* argv[])
{
#ifndef _POSIX_THREADS
	printf("nonono\n");
	exit(1);
#else
	printf("yes yes yes \n");
#endif
	pthread_t thread_id;
	char buf[] = "nice";
	if ( pthread_create(&thread_id, NULL, pthread_echo, (void*)"hello" ) != 0)
		err_ret("pthread_create error");
	if ( pthread_create(&thread_id, NULL, pthread_echo, (void*)buf ) != 0)
		err_ret("pthread_create error");
	pthread_echo((void*) "main");
	sleep(10);
    return 0;
}

