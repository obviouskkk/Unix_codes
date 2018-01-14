#########################################################################
# File Name: make_main.sh
# Author: zzy
# mail: 942744575@qq.com
# Created Time: Fri 12 Jan 2018 04:40:10 PM CST
#########################################################################
#!/bin/bash
gcc -Wall -fpic -ldl -Wno-unused -g    -fhosted -D_REENTRANT -D_GNU_SOURCE  -z defs  -o main main.c
