# Quicksort Challenge

This challenge requires the dev to create an integer quicksort
function to fulfill the requirements of program.c 

The framework for a quicksort implmentation has been created
but left empty.

program.c has been setup to generate N random numbers into an 
array. Print the unsorted array. Perform a quicksort, and re-
print the array in sorted format.
A simple test has been created to check the validity of the 
sorted array.

When the quicksort function has been implmented, compile and
execute the program using the makefile, and check the command
line for success or failure messages.

To setup the challenge:
1. Create a new folder, say 01. (```mkdir 01```)
2. Copy the contents of 00 to 01 (or whichever created in 1.) (```cp 00/* 01/```)
3. Implement the empty function in quicksort.c
4. Run 'make' in a terminal whilst in the folder created in 1. (```make```)
5. Check for 'Success' message.

Note. If the make file does not compile, check the settings in
makefile are compatible with your compiler. They are currently
setup for gcc with c99 standard.
