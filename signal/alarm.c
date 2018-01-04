/* ***********************************************************************

  > File Name: alarm.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 04 Jan 2018 04:12:23 PM CST

 ********************************************************************** */

#include "../apue.h"
#include "signal.h"

static void sig_alrm(int signo)
{
	char buf[]={"hello\n"};
	write(1,buf, strlen(buf) );
	alarm(3);
}

int main(int argc, const char* argv[])
{
	unsigned int seconds = alarm(1);
	printf("alarm:%d", seconds);
	if( signal(SIGALRM, sig_alrm  ) == SIG_ERR )
		err_exit("sinal error");
	//sleep(100); //alarm触发，sleep结束(闹钟结束就起来，233333)
	while(1);
    return 0;
}

