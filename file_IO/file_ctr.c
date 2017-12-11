/* ***********************************************************************

  > File Name: file_ctr.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 28 Nov 2017 03:30:16 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, const char* argv[])
{
	int fd = open ("test.txt", O_APPEND);
	int w_len = write(fd, "hello world" ,11);
	printf("%d\n",w_len);
    return 0;
}

