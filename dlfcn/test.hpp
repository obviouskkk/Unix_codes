/* ***********************************************************************

  > File Name: test.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 12 Jan 2018 04:08:24 PM CST

 ********************************************************************** */


#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>


class Base
{
public:
	virtual int add(int a, int b) = 0;
	virtual ~Base();
};

typedef Base* (*base_t)();

extern base_t dl_base;


class Derive: public Base{
public:
	int add(int a, int b);
};

#endif //__TEST_H__
