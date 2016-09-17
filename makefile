CC = gcc
CFLAGS = -Wall -g -I include

# recursively find all files with the source file extension
FILES = $(call rwildcard,src/,*.c)
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

all:
	$(CC) $(CFLAGS) $(FILES) -o bin/lol

# dependencies go below
