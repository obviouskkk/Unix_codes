/* ***********************************************************************

  > File Name: abort.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 16 Jan 2018 02:26:09 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <string.h>

#include <signal.h>

#include "../apue.h"
/*
struct sigaction {
	void     (*sa_handler)(int);
	void     (*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t   sa_mask;
	int        sa_flags;
	void     (*sa_restorer)(void);

};
*/

void sig_abort()
{
	char * buf = "hello\n";
	write(1, buf, strlen(buf));
}


/*
 * posix 要求的abort实现
 * 向进程发送一个SIGABRT信号
 * 允许捕捉SIGABRT信号，但是返回后abort终止进程
 * abort无视进程对此信号的阻塞和忽略
 * 
*/
void Abort()
{
	sigset_t mask;
	struct sigaction action;
	
	if (sigaction(SIGABRT, NULL, &action) < 0)
		err_ret("sigaction error %s", strerror(errno) );
	if(action.sa_handler ==SIG_IGN){//忽略
		action.sa_handler = SIG_DFL;//默认
		sigaction(SIGABRT, &action, NULL);
	}
	if(action.sa_handler == SIG_DFL)
		fflush(NULL);//冲洗所有流
	
	//阻塞处理SIGABRT外的所有信号
	sigfillset(&mask);
	sigdelset(&mask, SIGABRT);
	sigprocmask(SIG_SETMASK, &mask, NULL);
	kill(getpid(), SIGABRT);
	
	//如果有捕捉该信号，已经返回
	fflush(NULL);
	action.sa_handler = SIG_DFL;
	sigaction(SIGABRT, &action, NULL);
	kill(getpid(), SIGABRT);

	exit(1);//never be executed 永远不会执行
}


int main(int argc, const char* argv[])
{
	if(signal(SIGABRT, sig_abort) == SIG_ERR)
		err_ret("signal error");
	printf("hello ");//验证是否会冲洗流
	sleep(3);
	Abort();
	printf("hello\n");
    return 0;
}

