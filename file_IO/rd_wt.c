/* ***********************************************************************

  > File Name: rd_wt.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 06 Dec 2017 01:59:50 PM CST

 ********************************************************************** */

#include <stdio.h>

#include "common.h"

int main(int argc, const char* argv[])
{
	int fd = 0;
	if ( (fd = open("./test.txt" ,O_RDWR|O_CREAT) ) < 0 ){
		printf("%s\n",strerror(errno));
		exit(1);
	}
	char r_buf[4096] ={0};
	int length = write(fd ,"hello world hello world hello world ",36);
	if(length < 0){
		printf("%s\n",strerror(errno));
		exit(2);
	}
	int now_cur = (int)lseek(fd , 0 ,SEEK_CUR);
	printf("write_down :%d\n",now_cur);
	/*内核只维护了一个文件的偏移量，写完了之后，文件偏移量被移动到最后，无法读出	*/
	/*
	now_cur = (int)lseek(fd , 0 ,SEEK_SET);
	printf("write down :%d\n",now_cur);
	now_cur = (int)lseek(fd , 0 ,SEEK_CUR);
	printf("write down :%d\n",now_cur); //36 
	*/
	now_cur = (int)lseek(fd , 0 ,SEEK_SET);
	length = read(fd ,r_buf ,36);
	if(length < 0){
		printf("%s\n",strerror(errno));
		exit(3);
	}
	printf("%s\n",r_buf);
	
	now_cur = (int)lseek(fd , 0 ,SEEK_CUR);
	printf("read down: %d\n",now_cur);
	memset(r_buf, 4096 ,'\0');
	//lseek(fd ,100 ,SEEK_SET);
	//now_cur = (int)lseek(fd , 0 ,SEEK_CUR);
	//printf("lseek down: %d\n",now_cur);

	write(fd ,"hello world hello world hello world ",36);

	length = read(fd ,r_buf ,36);
	if(length < 0){
		printf("%s\n",strerror(errno));
		exit(3);
	}
	r_buf[length+1] = '\0';
	printf("%s\n",r_buf);

	now_cur = (int)lseek(fd , 0 ,SEEK_CUR);
	printf("read down: %d\n",now_cur);

    return 0;
}

