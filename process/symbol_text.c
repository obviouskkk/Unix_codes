/* ***********************************************************************

  > File Name: symbol_text.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 14 Dec 2017 10:53:55 AM CST

 ********************************************************************** */

#include <stdlib.h>

int a = 0; //全局初始化区  
char *p1; //全局未初始化区  

int main()  
{  
	static int c =0; //全局（静态）初始化区  
	static int fa = 1;
	int b; //栈  
	char s[] = "abc"; //栈  
	char *p2; //栈  
	char *p3 = "123456"; //"123456\0"在常量区，p3在栈上。  
	char *p4 = "123456"; //"123456\0"在常量区，p3在栈上。  
	p1 = (char *)malloc(10);  
	p2 = (char *)malloc(20); //分配得来得10和20字节的区域就在堆区。  
	return 0;
}

//size a.out
//text	   data	    bss	    dec	    hex	 filename
//1271	    552	     24	   1847	    737	 a.out


