CC = gcc
CFLAGS = -g -Wall -Werror -pedantic-errors

all: sortargs

sortargs: sortargs.o linked_list.o node.o
	$(CC) $(CFLAGS) sortargs.o linked_list.o node.o -o sortargs

sortargs.o: sortargs.c
	$(CC) $(CFLAGS) -c sortargs.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

node.o: node.c node.h
	$(CC) $(CFLAGS) -c node.c

.PHONY: clean
clean:
	rm -f sortargs *.o
