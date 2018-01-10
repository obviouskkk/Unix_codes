/* ***********************************************************************

  > File Name: sig_action.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 10 Jan 2018 03:15:46 PM CST

 ********************************************************************** */

#include "../apue.h"

typedef void Sigfunc(int);

//使用sigaction实现signal
Sigfunc* signal(int signo, Sigfunc* func)
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	//begin
	if(signo == SIGALRM){
#ifdef SA_INTERRUPT
		act.sa_flags |= SA_INTERRUPT;
#endif
	} else {
		act.sa_flags |= SA_RESTART;
	}
	//end
	//if want to prevent restart，change code like this between begin and end
	/*
#ifdef SA_INTERRUPT
	act.sa_flags |= SA_INTERRUPT;
#endif
	 */
	if(sigaction(signo , &act, &oact) < 0)
		return(SIG_ERR);
	return (oact.sa_handler);
}

void func(int signo)
{
	char buf[]="heelo";
	write(1, buf, strlen(buf));
}

int main(int argc, const char* argv[])
{
	if( signal(SIGQUIT, func) == SIG_ERR )
		err_exit("signal err_error");
	sleep (100);
	printf("awake\n");
    return 0;
}

