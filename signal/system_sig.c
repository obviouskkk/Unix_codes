/* ***********************************************************************

  > File Name: system_sig.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 16 Jan 2018 03:39:33 PM CST

 ********************************************************************** */
#include <string.h>

#include <signal.h>
#include <unistd.h>

#include "../apue.h"
/*
 * Posix.1标准的system
 * 忽略SIGINT和SIGQUIT，阻塞SIGCHLD
*/


/*
   struct sigaction {
   void     (*sa_handler)(int);
   void     (*sa_sigaction)(int, siginfo_t *, void *);
   sigset_t   sa_mask;
   int        sa_flags;
   void     (*sa_restorer)(void);
   };
 */
int System(const char* cmd_srting)
{
	if (cmd_srting == NULL)
		return(1);
	
	//忽略SIGINT SIGQUIT 并保存旧的action
	struct sigaction new_act, save_sigint, save_sigquit;
	new_act.sa_handler = SIG_IGN;//忽略
	sigemptyset(&new_act.sa_mask);
	new_act.sa_flags = 0;
	if(sigaction(SIGINT, &new_act, &save_sigint) < 0 )
		return -1;
	if(sigaction(SIGQUIT, &new_act, &save_sigquit) < 0)
		return -1;

	//阻塞SIGCHLD, 并保存旧的文件屏蔽字
	sigset_t mask, savemask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGCHLD);
	if ( sigprocmask(SIG_BLOCK, &mask, &savemask) < 0 )
		return -1;

	pid_t pid;
	int status;
	if (( pid = fork()  ) < 0 )
		return(-1);
	else if (pid == 0) {//child
		//恢复子进程对信号的阻塞和忽略
		sigaction(SIGINT, &save_sigint, NULL);
		sigaction(SIGQUIT, &save_sigquit, NULL);
		sigprocmask(SIG_SETMASK, &savemask, NULL);

		execl("/bin/sh", "sh", "-c", cmd_srting, (char *) 0);
		_exit(127);
	} else {//parent
		while(waitpid(pid, &status, 0) < 0) //linux不能用wait
			if(errno != EINTR){
				status = -1;
				break;
			}
	}
	//恢复父进程自身对信号的阻塞和忽略
	sigaction(SIGINT, &save_sigint, NULL);
	sigaction(SIGQUIT, &save_sigquit, NULL);
	sigprocmask(SIG_SETMASK, &savemask, NULL);
	
	return status;
}

int main(int argc, const char* argv[])
{
	System("echo \"hello world!\"");
    return 0;
}

