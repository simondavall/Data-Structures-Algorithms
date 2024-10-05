# Hash Table Challenge

This challenge requires the dev to create a hash table to
fulfill the requirements of program.c 

The framework for a hash table implmentation has been created
but left empty.

program.c has been setup to generate an array of 1000 random
codes of the for "ad-#". These are then added to the hash table,
before performing various functions (find, remove and print) to
test the functions and then destroying itself, freeing memory.

When the hash_table functions have been implmented, compile the
program using the makefile, and check the command line for 
success or failure messages.

To setup the challenge:
1. Create a new folder, say 01. (```mkdir 01```)
2. Copy the contents of 00 to 01 (or whichever created in 1.) (```cp 00/* 01/```)
3. Implement the empty functions in hash_table.c
4. Run 'make' in a terminal whilst in the folder created in 1. (```make```)
5. Check for 'Success' message.

Note. If the make file does not compile, check the settings in
makefile are compatible with your compiler. They are currently
setup for gcc.
