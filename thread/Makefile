CC=gcc
CFLAGS= -Wall -ldl -fpic -ggdb -DDEBUG
LD_FLAGS= -lpthread

BINS=pthread thread_exit thread_cleanup pthread_mutex

all:$(BINS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^ $(LD_FLAGS)

clean:
	@rm -f a.out  $(BINS)
