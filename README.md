# c

University module on the C language

## Pointers

The `*` character before a pointer name refers to the value stored at that memory address.

The `&` character before a variable name refers to the pointer which that variable is stored in.

## Program structure

### Imports

Use `#import` to import libraries. The most common ones are:

```c
#import
<stdio.h>
#import
<stdlib.h>
```

### Structs & typedefs

Begin the file with structs and typedefs

### Prototypes

You should have the function prototypes before the main method. These describe the shape of the function, ie its name,
its arguments and its return type.

### Main method

The main method should return 0 for a successful exit code

### Function definitions

Here you should define the code for the function prototypes declared earlier. These are used in the main method.

## Large program structures

The above structure is how a single file program can be structured, but larger programs require a different structure:

- `struct`s and `typedefs` go into a `.h` file
- function definitions go into the same named file, but with a `.c` extension, and `#include` `.h`
- any file can use this functionality by `#include`ing the `.h` file

To compile and link this program:

Compile each individual file

```shell
gcc -ansi -I./ -c file.c -o file.o
```

Link them all together

```shell
gcc file1.o file2.o file3.o -o outputname
```

where output name is the same name as the file containing a main function

Hash include guard your modules to stop multiple declarations of the same thing
