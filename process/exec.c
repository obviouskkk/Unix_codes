/* ***********************************************************************

  > File Name: exec.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 22 Dec 2017 03:55:48 PM CST

 ********************************************************************** */

#include <stdio.h>
#include "../apue.h"
#include <unistd.h>

int main(int argc, const char* argv[])
{
	char *env[]={"USER=zzy", "PATH=/tmp", NULL};
	char *argvl[] = {"argv0", "/home/zzy/Unix_codes/process/hello.sh", "1"};

	pid_t pid ;
	//execlp
	if ( (pid = fork() )< 0 )
		err_ret("fork error");
	else if (pid == 0){
		if ( execlp("./hello.sh","argvl","1" ,NULL) < 0 )
			perror("execl error");
	} 
	if (waitpid(pid, NULL, 0) < 0)
		err_exit("wait error");
	
	//execve
	if ( (pid = fork() ) < 0 )
		err_ret("fork error");
	else if (pid == 0){
		if (execve("/bin/bash", argvl, env ) < 0)
			perror("execl error");
	}
	if (waitpid(pid, NULL, 0) < 0)
		err_exit("wait error");
	exit(0);
}

