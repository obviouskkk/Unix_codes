/* ***********************************************************************

  > File Name: myls.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 27 Nov 2017 05:19:13 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <dirent.h>

#include "../apue.h"
int main(int argc, const char* argv[])
{
	DIR * dp;
	struct dirent * dirp;
	if(argc != 2){
		err_ret("usage: ls directroy_name");
		return -1;
	}
	if( (dp = opendir(argv[1])) == NULL){
		err_sys("can't open %s", argv[1]);
		exit(1);
	}
	while( (dirp = readdir(dp)) != NULL  )
		printf("%s ",dirp->d_name);
	printf("\n");
	closedir(dp);
    return 0;

}

