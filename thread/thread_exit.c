/* ***********************************************************************

  > File Name: thread_exit.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 17 Jan 2018 03:37:22 PM CST

 ********************************************************************** */

#include "../apue.h"

#include <pthread.h>

static void * pexit(void * arg)
{
	sleep(1);
	printf("will exit\n");
	pthread_exit((void *)1);
}

struct user
{
	int a, b, c, d;

};

static void * pexit_struct(void * arg)
{
	static struct user user_1 = { 1, 2, 3, 4 };
	printf("pexit_struct\n");
	pthread_exit((void*)&user_1);
}


int main(int argc, const char* argv[])
{

	pthread_t tid, tid_2;
	
	//静态
	if ( pthread_create(&tid_2 ,NULL ,pexit_struct, NULL) != 0)
		err_ret("pthread_create error");

	//一个简单的例子
	if ( pthread_create(&tid ,NULL ,pexit, NULL) != 0)
		err_ret("pthread_create error");
	void * t_ret ;
	if ( pthread_join(tid, &t_ret) != 0 )
		err_ret("pthread_join error");
	printf("thread exit :%ld\n", (long )t_ret);


	void * struct_ret ;
	if ( pthread_join(tid_2, &struct_ret) != 0 )
		err_ret("pthread_join error");
	printf("thread exit a:%d\n", ((struct user * )struct_ret)->a);
	printf("thread exit b:%d\n", ((struct user * )struct_ret)->b);
	printf("thread exit c:%d\n", ((struct user * )struct_ret)->c);
	printf("thread exit d:%d\n", ((struct user * )struct_ret)->d);

    return 0;
}

