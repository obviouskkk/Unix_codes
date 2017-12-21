/* ***********************************************************************

  > File Name: setbuf.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 07 Dec 2017 03:54:59 PM CST

 ********************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char buf[BUFSIZ];
	setbuf(stdout, buf);
	printf("Hello, world!\n");
	sleep(2);
	printf("Hello, world!\n");
	fflush(stdout);
	sleep(2);
	printf("Hello, world!");
	sleep(2);
	return 0;

}



