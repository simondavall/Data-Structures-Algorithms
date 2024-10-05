CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

.PHONY: test
test: main
	./main

main: program.o quicksort.o
	$(CC) -o main program.o quicksort.o $(CFLAGS)

program.o: program.c quicksort.h
	$(CC) -c program.c $(CFLAGS)

quicksort.o: quicksort.c quicksort.h
	$(CC) -c quicksort.c $(CFLAGS)
