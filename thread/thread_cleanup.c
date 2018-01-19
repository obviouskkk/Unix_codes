/* ***********************************************************************

  > File Name: thread_cleanup.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 17 Jan 2018 05:12:48 PM CST

 ********************************************************************** */

#include <pthread.h>
#include "../apue.h"

void * clean(void * arg)
{
	printf("clean up :%s\n", (char*) arg);
	return NULL;
}


void * thread_1(void * arg)
{
	printf("thread_1 begin\n");

	pthread_cleanup_push(clean, (void *)"hello");
	printf("thread_1 \n");
	pthread_cleanup_pop(1); //必须调用pop
	pthread_exit(NULL);
}


int main(int argc, const char* argv[])
{
	pthread_t tid;
	int err = pthread_create(&tid, NULL, thread_1, NULL);
	if (err != 0)
		err_ret("pthread_create error");
	err = pthread_join(tid, NULL);
	if (err != 0)
		err_ret("pthread_join error");
    return 0;
}

