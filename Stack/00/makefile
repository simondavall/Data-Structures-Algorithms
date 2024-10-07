CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

.PHONY: test
test: main
	./main

main: program.o stack.o
	$(CC) -o main program.o stack.o $(CFLAGS)

program.o: program.c stack.h
	$(CC) -c program.c $(CFLAGS)

stack.o: stack.c stack.h
	$(CC) -c stack.c $(CFLAGS)
