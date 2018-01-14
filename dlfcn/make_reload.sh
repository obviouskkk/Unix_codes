#########################################################################
# File Name: make_reload.sh
# Author: zzy
# mail: 942744575@qq.com
# Created Time: Fri 12 Jan 2018 06:28:24 PM CST
#########################################################################
#!/bin/bash
g++ -fPIC -Wall -DDEBUG -g  -shared  -o libload.so reload.cpp
