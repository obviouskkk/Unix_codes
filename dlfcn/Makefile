CC=gcc
CCPLUS=g++

CFLAGS=-Wall -fPIC -ggdb -ldl 
LD_FLAGS=-L../dlfcn -lreload

all:libreload.so libtest.so
libreload.so:reload.cpp reload.hpp common.hpp
	$(CC) $(CFLAGS) -shared -o $@ $^

libtest.so:test.cpp test.hpp common.hpp
	$(CC) $(CFLAGS) -shared -o $@ $^

%.o: %.cpp
	$(CC) $(INCLUDE_FLAGS) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

clean:
	@rm -rf *.o libtest.so  libreload.so
