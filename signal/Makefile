CC=gcc

FLAGS= -ggdb  -Wall
LDFLAGS= -ldl 
LDLIBS=

BINS=alarm sleep sigmask sig_action

all:$(BINS)

%:  %.c
	$(CC) $(FLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)


clean:
	rm -f *.o $(BINS) a.out
