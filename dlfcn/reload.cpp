/* ***********************************************************************

  > File Name: reload.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 12 Jan 2018 06:21:12 PM CST

 ********************************************************************** */


#include "reload.hpp"

extern "C" void handle_reload()
{
	sess::get_sess()->doall();
	printf("hello world\n");
}
