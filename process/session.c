/* ***********************************************************************

  > File Name: session.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 28 Dec 2017 02:36:37 PM CST

 ********************************************************************** */

#include "../apue.h"

int main(int argc, const char* argv[])
{
	pid_t sid = getsid(0);
	printf("sid :%d\n",sid);
	pid_t pid;
	if((pid=fork()) < 0  )
		err_ret("fork error");
	else if(pid == 0){
		setsid();
		printf("child sid:%d\n",getsid(0));
		printf("child ppid:%d\n",getppid());
		printf("child pgid:%d\n",getpgrp() );
		system("echo \"hello world\"");

	} else {
		sleep(10);
	}
    return 0;
}

