CC = gcc
CFLAGS = -g -Wall -Werror -pedantic-errors

all: lowercase

lowercase: lowercase.o mystring.o
	$(CC) $(CFLAGS) lowercase.o mystring.o -o lowercase

lowercase.o: lowercase.c
	$(CC) $(CFLAGS) -c lowercase.c

mystring.o: mystring.c mystring.h
	$(CC) $(CFLAGS) -c mystring.c

.PHONY: clean
clean:
	rm -f lowercase *.o
