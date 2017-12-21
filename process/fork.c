/* ***********************************************************************

  > File Name: fork.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 19 Dec 2017 03:33:43 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int var = 10;
int main(int argc, const char* argv[])
{
	pid_t id ;
	printf("before fork\n");
	if (  ( id = fork() ) < 0 ) {
		exit(2);
	} else if (id == 0) {//child
		var++;
	} else {//parent
		sleep(2);
	}
	printf("%d\n",var);
    return 0;
}

