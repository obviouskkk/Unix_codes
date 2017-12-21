/* ***********************************************************************

  > File Name: wait.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 21 Dec 2017 02:12:32 PM CST

 ********************************************************************** */

#include <stdio.h>
#include "../apue.h"

int main(int argc, const char* argv[])
{
	pid_t pid;
	int status;
	/*
	if ( (pid = fork() ) <  0)
		err_ret("fork error");
	else if ( pid > 0 ){
		printf("wait begin\n");
		if (wait(&status) != pid )
			err_ret("wait error");
		printf("wait done\n");
	} else {
		sleep(5);
		exit(6);
	}
	pr_exit(status);
	*/
	if( (pid = fork() ) < 0 )
		err_ret("fork error");
	else if (pid > 0){
	} else if (pid == 0){
		abort();
	}
	printf("wait begin\n");
	sleep(2);
	waitpid(pid , &status ,WNOHANG);
	printf("wait done\n");
	pr_exit(status);
	printf("parent exit\n");
    return 0;
}

