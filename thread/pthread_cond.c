/* ***********************************************************************

  > File Name: pthread_cond.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 24 Jan 2018 03:10:18 PM CST

 ********************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <pthread.h>

#include "../apue.h"

pthread_cond_t pc[4] = {PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER };
pthread_mutex_t pm[4] = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER};
int fds[4];

int next_id(int i)
{
	int ret = (i == 4) ? 1 : ++i;
	return ret;
}

/*
void* write_file(void * index)
{	
	int i = *(int*)index;
	int fd = fds[i];
	char buf[]="1 ";
	while(1){
		pthread_cond_wait(&pc[i], &pm[i]);
		int len = write(fd, (void*)buf, (size_t)strlen(buf));
		if(len <= 0)
			perror("write error");
		else{
			printf("write 1");
			pthread_cond_signal(&pc[next_id(i)]);
			fd = fds[next_id(i)];
		}
	}
	pthread_exit(NULL);
}
*/

void* print_1(void * index)
{
	int i = *(int*)index;
	int fd = fds[i];
	printf("fd is %d", fd);
	char buf[]="1 ";
	int len = write(fd, (void*)buf, (size_t)strlen(buf));
	if(len <= 0)
		perror("write error");
	else{
		printf("write 1");
		pthread_cond_signal(&pc[1]);
		fd = fds[(++i)%2];
	}
	pthread_mutex_lock(&pm[0]);
	while(1){
		pthread_cond_wait(&pc[0], &pm[0]);
		len = write(fd, (void*)buf, (size_t)strlen(buf));
		if(len <= 0)
			perror("write error");
		else{
			//printf("write 1 %d\n", fd);
			pthread_cond_signal(&pc[1]);
			fd = fds[(++i)%2];
		}
	}
	pthread_mutex_unlock(&pm[0]);
}

void* print_2(void * index)
{
	int i = *(int*)index;
	int fd = fds[i];
	char buf[]="2 ";
	printf("fd is %d", fd);
	pthread_mutex_lock(&pm[1]);
	while(1){
		pthread_cond_wait(&pc[1], &pm[1]);
		int len = write(fd, (void*)buf, (size_t)strlen(buf));
		if(len <= 0)
			perror("write error");
		else{
			printf("write 2 %d\n", fd);
			//pthread_cond_signal(&pc[0]);
			fd = fds[(++i)%2];
		}
	}
	pthread_mutex_unlock(&pm[1]);
}


int main(int argc, const char* argv[])
{
	fds[0] = open("./A", O_WRONLY | O_CREAT |O_TRUNC, S_IRUSR|S_IWUSR|S_IXUSR);
	fds[1] = open("./B", O_WRONLY | O_CREAT |O_TRUNC, S_IRUSR|S_IWUSR|S_IXUSR);
	fds[2] = open("./C", O_WRONLY | O_CREAT |O_TRUNC, S_IRUSR|S_IWUSR|S_IXUSR);
	fds[3] = open("./D", O_WRONLY | O_CREAT |O_TRUNC, S_IRUSR|S_IWUSR|S_IXUSR);
	int a = 0  , b = 1;
	pthread_t thread_id[2];
	pthread_create(&thread_id[0], NULL, print_1, &a);
	pthread_create(&thread_id[1], NULL, print_2, &b);
	pthread_join(thread_id[0], NULL);
	pthread_join(thread_id[1], NULL);
    return 0;
}

