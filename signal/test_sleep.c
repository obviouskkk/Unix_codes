/* ***********************************************************************

  > File Name: test_sleep.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 04 Jan 2018 05:35:48 PM CST

 ********************************************************************** */

#include <signal.h>
#include "../apue.h"

static void sig_chld(int signo)
{
	int status;
	wait(&status);
}



int main(int argc, const char* argv[])
{
	pid_t pid;
	signal(SIGCHLD ,sig_chld);
	pid = fork();

	if (pid == 0){
		sleep(10);
		printf("child exit\n");
		exit(0);
	}
	sleep(100);
    return 0;
}

