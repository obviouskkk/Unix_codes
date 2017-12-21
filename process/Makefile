CC=gcc
FLAGS= -Wall -ggdb -ldl


fork:fork.o
	$(CC) -o $@ $^ $(FLAGS)
%.o: %.c
	$(CC) -c -o $@ $<


clean:
	rm *.o fork

