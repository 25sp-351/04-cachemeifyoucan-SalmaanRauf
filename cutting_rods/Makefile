CC = gcc
CFLAGS = -Wall

all: rod_cut_lru rod_cut_fifo # make both versions

# lru version
rod_cut_lru: main.c cache_lru.c cache.h
	$(CC) $(CFLAGS) -o rod_cut_lru main.c cache_lru.c

# fifo version
rod_cut_fifo: main.c cache_fifo.c cache.h
	$(CC) $(CFLAGS) -o rod_cut_fifo main.c cache_fifo.c

# cleanup
clean:
	rm -f rod_cut_lru rod_cut_fifo
