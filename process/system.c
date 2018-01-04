/* ***********************************************************************

  > File Name: system.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 26 Dec 2017 03:15:49 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
	const char * str = "echo \"hello world!\"";
	system(str);
	//字符串拼接
    return 0;
}

