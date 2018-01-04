/* ***********************************************************************

  > File Name: vfork.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 27 Dec 2017 03:29:28 PM CST

 ********************************************************************** */

#include "../apue.h"

int globvar = 6;


int main(int argc, const char* argv[])
{
	pid_t pid;
	int var ;
	var = 88;

	printf("before vfork\n");
	if ((pid = vfork()) < 0)
		err_exit("vfork error");
	else if (pid == 0){
		globvar++;
		var++;
		exit(0);
	}
	printf("pid=%d, glob =%d, var=%d\n",(long)getpid(),globvar, var);
    exit(0);
}

