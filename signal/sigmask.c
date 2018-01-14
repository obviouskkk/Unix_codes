/* ***********************************************************************

  > File Name: sigmask.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 08 Jan 2018 04:35:38 PM CST

 ********************************************************************** */

#include "../apue.h"

void proc_mask(const char* str)
{
	sigset_t sigset;
	int errno_save;

	errno_save = errno;
	if (sigprocmask(0,NULL, &sigset) < 0)
		err_ret("sigprocmask error");
	else {
		printf("%s", str);
		if(sigismember(&sigset, SIGINT) )
			printf("	SIGINT");
		if(sigismember(&sigset, SIGQUIT) )
			printf("	SIGQUIT");
		if(sigismember(&sigset, SIGUSR1) )
			printf("	SIGUER1");
		if(sigismember(&sigset, SIGALRM) )
			printf("	SIGUER1");
		if(sigismember(&sigset, SIGHUP) )
			printf("	SIGHUP");
		printf("\n");
	}
	errno = errno_save;

}

void sig_mask()
{
	sigset_t sigset, sigoset;
	sigaddset(&sigset, SIGHUP);

	if( sigprocmask(SIG_BLOCK, &sigset,&sigoset ) < 0 )
		err_ret("sigprocmask error");
}

int main(int argc, const char* argv[])
{
	sig_mask();
	proc_mask("hello");
	sleep(10);
    return 0;
}

