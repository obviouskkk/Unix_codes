CC=gcc
FLAGS= -Wall -ggdb -ldl
bin=fork symbol_text 

all:$(bin) 


symbol_text:symbol_text.o
	$(CC) -o $@ $^ $(FLAGS)
fork:fork.o
	$(CC) -o $@ $^ $(FLAGS)


%.o: %.c
	$(CC) -c -o $@ $<


clean:
	rm *.o $(bin)

