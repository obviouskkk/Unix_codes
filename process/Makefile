CC=gcc
FLAGS= -Wall -ggdb -ldl
bin=fork symbol_text  exec

all:$(bin) 


symbol_text:symbol_text.o
	$(CC) -o $@ $^ $(FLAGS)
fork:fork.o
	$(CC) -o $@ $^ $(FLAGS)
exec:exec.o

%.o: %.c
	$(CC) -c -o $@ $<


clean:
	rm *.o $(bin) a.out

