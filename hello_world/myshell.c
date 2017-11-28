/* ***********************************************************************

  > File Name: myshell.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 28 Nov 2017 02:26:20 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "./apue.h"

#define MAX_LINE 1024
int main(int argc, const char* argv[])
{
	char buf[MAX_LINE];
	pid_t pid = -1;
	int status;
	printf("%% ");
	while ( fgets(buf, MAX_LINE, stdin) != NULL){
		if(buf[strlen(buf) -1] == '\n')
			buf[strlen(buf) -1] = 0;
		if( (pid = fork() ) < 0 ){
			err_ret("fork error");
		} else if(pid == 0){
			execlp(buf, buf ,(char*)0 );
			err_ret("could't execute: %s", buf);
			exit(127);
		}

		if((pid = waitpid(pid, &status, 0) ) < 0)
			err_sys("waitpid error");
		printf("%% ");
	}
    return 0;
}

