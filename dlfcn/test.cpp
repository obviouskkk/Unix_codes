/* ***********************************************************************

  > File Name: test.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 12 Jan 2018 04:44:56 PM CST

 ********************************************************************** */

#include "test.hpp"
#include <stdio.h>


extern "C" Base * ret_class()
{
	Base * p = new Derive();
	return p;
}


int Derive::add(int a, int b)
{
	printf("hello %d\n", 100  );
	return 0;
}
