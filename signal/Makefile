CC=gcc

FLAGS= -ggdb  -Wall

BINS=alarm

all:$(BINS)

alarm:alarm.o
	$(CC) -o $@ $^ $(FLAGS)




%.o: %.c
	$(CC) -c -o $@ $<


clean:
	rm -f *.o $(BINS) a.out
