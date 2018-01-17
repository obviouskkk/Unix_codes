CC=gcc
CFLAGS= -Wall -ldl -fpic
LD_FLAGS= -lpthread

BINS=pthread thread_exit

all:$(BINS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^ $(LD_FLAGS)

clean:
	@rm -f a.out  $(BINS)
