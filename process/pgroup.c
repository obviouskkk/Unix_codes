/* ***********************************************************************

  > File Name: pgroup.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 28 Dec 2017 10:41:39 AM CST

 ********************************************************************** */


#include "../apue.h"

int main(int argc, const char* argv[])
{
	pid_t pid;
	if((pid = fork()) < 0)
		err_ret("fork error");
	else if (pid > 0){
		printf(" parent pid:%d\n", getpid());
		printf(" parent group id :%d\n",getpgrp());
	} else{
		printf(" child pid:%d\n", getpid());
		printf(" child group id :%d\n",getpgrp());
		exit(1);
	}

	wait(NULL);
    return 0;
}

