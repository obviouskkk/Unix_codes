CC=gcc
FLAGS= -Wall -ggdb -ldl
bin=fork symbol_text  exec system times vfork pgroup session

all:$(bin) 


symbol_text:symbol_text.o
	$(CC) -o $@ $^ $(FLAGS)
fork:fork.o
	$(CC) -o $@ $^ $(FLAGS)
exec:exec.o
	$(CC) -o $@ $^ $(FLAGS)
system:system.o
	$(CC) -o $@ $^ $(FLAGS)
times:times.o
	$(CC) -o $@ $^ $(FLAGS)
vfork:vfork.o
	$(CC) -o $@ $^ $(FLAGS)
pgoup:pgoup.o
	$(CC) -o $@ $^ $(FLAGS)
session:session.o
	$(CC) -o $@ $^ $(FLAGS)

%.o: %.c
	$(CC) -c -o $@ $<


clean:
	rm -f *.o $(bin) a.out

