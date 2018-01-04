/* ***********************************************************************

  > File Name: sleep.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 04 Jan 2018 04:40:56 PM CST

 ********************************************************************** */
#include "../apue.h"
#include <signal.h>

static void sig_alrm(int signo){}

unsigned int sleep_1(unsigned int seconds)
{
	if (signal(SIGALRM,sig_alrm) == SIG_ERR) 
		return seconds;
	alarm(seconds);
	pause();
	return (alarm(0) );
}



int main(int argc, const char* argv[])
{
	printf("will sleep\n");
	sleep_1(10);
	printf("aweak\n");
    return 0;
}

