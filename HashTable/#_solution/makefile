CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

.PHONY: test
test: main
	./main

main: program.o hash_table.o
	$(CC) -o main program.o hash_table.o $(CFLAGS)

program.o: program.c hash_table.h
	$(CC) -c program.c $(CFLAGS)

hash_table.o : hash_table.c hash_table.h
	$(CC) -c hash_table.c
