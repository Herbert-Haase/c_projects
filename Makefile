# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c11 -pedantic

# Automatically find all source files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Default target
all: main

# Rule to create the executable
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to create object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f main $(OBJ)
