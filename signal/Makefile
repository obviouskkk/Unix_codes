CC=gcc

FLAGS= -ggdb  -Wall

BINS=alarm sleep sigmask sig_action

all:$(BINS)

sigmask:sigmask.o
	$(CC) -o $@ $^ $(FLAGS)
alarm:alarm.o
	$(CC) -o $@ $^ $(FLAGS)
sleep:sleep.o
	$(CC) -o $@ $^ $(FLAGS)
sig_action:sig_action.c
	$(CC) -o $@ $^ $(FLAGS)




%.o: %.c
	$(CC) -c -o $@ $<


clean:
	rm -f *.o $(BINS) a.out
