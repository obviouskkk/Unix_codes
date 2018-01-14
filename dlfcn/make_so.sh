#########################################################################
# File Name: make_so.sh
# Author: zzy
# mail: 942744575@qq.com
# Created Time: Fri 12 Jan 2018 04:40:30 PM CST
#########################################################################
#!/bin/bash
g++ -fPIC -Wall -DDEBUG -g  -shared  -o libtest.so test.cpp  
