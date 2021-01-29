#!/bin/bash

# This should compile, link and run a C program

# first argument is name of the file (exluding the file extension)

echo "Compiling and running $1.c"
gcc -c $1.c -o $1.o

gcc $1.o -o $1

./$1
