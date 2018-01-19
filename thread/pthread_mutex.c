/* ***********************************************************************

  > File Name: pthread_mutex.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 18 Jan 2018 11:23:34 AM CST

 ********************************************************************** */

#include "../apue.h"
#include <pthread.h>

struct thread_shared
{
	int id;
	pthread_mutex_t lock;
	int count;
	/*more ...*/
};


struct thread_shared * init(int a)
{
	struct thread_shared * shared ;
	shared = (struct thread_shared*) malloc(sizeof(struct thread_shared) );
	if (shared == NULL){
		err_exit("malloc error");
	}
	shared->id = a;
	shared->count = 1;
	int err = pthread_mutex_init(&shared->lock, NULL );
	if(err != 0){
		free(shared);
		return NULL;
	}
	return shared;
}

void ptr_use(struct thread_shared * shared)
{
	pthread_mutex_lock(&shared->lock);
	++shared->count;
	pthread_mutex_unlock(&shared->lock);
}

void ptr_delete(struct thread_shared * shared)
{
	pthread_mutex_lock(&shared->lock);
	if ( --shared->count == 0 ){
		pthread_mutex_unlock(&(shared->lock) );
		pthread_mutex_destroy(&(shared->lock));
		free(shared);
	} else 
		pthread_mutex_unlock(&shared->lock);
}

int main(int argc, const char* argv[])
{
	struct thread_shared* shared = init(1);

	ptr_use(shared); //线程安全
	ptr_delete(shared);//线程安全

    return 0;
}

