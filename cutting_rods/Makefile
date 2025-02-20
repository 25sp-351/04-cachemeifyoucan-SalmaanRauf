# Compiler options
CFLAGS = -g -Wall

# Default target
all: main

# Rule for building the main executable
main: main.c
	$(CC) $(CFLAGS) -o main main.c

# Rule for cleaning up build artifacts
clean:
	rm -f main
