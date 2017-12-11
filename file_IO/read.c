/* ***********************************************************************

  > File Name: read.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 04 Dec 2017 04:59:42 PM CST

 ********************************************************************** */

#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, const char* argv[])
{
	int fd = open("test.txt" , O_RDWR);
	if(fd == -1){
		printf("%s\n",strerror(errno));
		return 0;
	}
	char buf[4096];
	int len = read(fd, buf, 4095);
	printf("len:%d\n%s", len,buf);
    return 0;
}

