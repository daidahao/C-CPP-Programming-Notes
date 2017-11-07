# Mid-term Exam Review

# Lecture 1

## Pointer

`ptr_my_var = &my_var`

`*ptr_my_var`

32-bit machine: 4 bytes

64-bit machine: 8 bytes

### More on Pointers (Lecture 3)

`&` returns the address of a variable

### Pointer declaration
`data_type *pointer_name`

**Declaring a pointer ONLY RESERVES MEMORY FOR THE POINTER**

> You assign to it the address of memory reserved by other means.

`int my_array[25];`
Declares two things:
1. Room to store 25 consecutive integers
2. A pointer to the first one

### `sizeof()`
returns a long

Gives the size of what was reserved. The argument can be a data type as well as a variable name. Very useful.

### NULL
Initialize pointers to a variable address or to NULL!

NULL is a constant which represents a pointer with all bits set to zero.

Functions that return a pointer return NULL when they fail or are done.

**An uninitialized pointer could hit memory anywhere!**

**A pointer holds a reference to a variable value.**

### Dereferencing `*`
`*` operator

## Data types

Data Type  |  Length (byte)
--|--
char  |  1
short  |  2
int | 4
long | 8
float | 4
double* | 8
\* Exponent 11 bits, Radix 52 bits

### Integer Operations

- Usual operators +, -, *, /
- Modulo %
- Bit operations &, |, ~
- Bit shift \>>, <<

## Array

`my_var` Value

`my_arr[n]` Value

`my_arr` Address <-> `&(my_arr[0])`

### "Out of Bound"
Anything can happen.

## String
Char array

### End-of-string marker

`'\0'` byte with all bits set to zero

```c
char my_text[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

`'A'` One character
`"A"` Two characters <-> `{'A', '\0'}`

## Functions are not nested
All functions are at the same level.

## Compiling a C program
1. A preprocessor runs over your code
The preprocessor simply replaces text. It looks for lines that start with a `#`, which are preprocessor instructions. `#include` says to fetch a header file and insert it into the code. `#define` gives a name to a constant value. Whenever the name is found in the code, it will be replaced by the value.
1. Compiler turns the code into an "object file".
2. Linker adds the code of standard C functions and turns the program into an "executable" program.

> A compiled language is faster and uses fewer resources.

`gcc log_sample.c –o log_sample -lm`

> Libraries all have a name that starts with "lib" and therefore (because C developers like shortcuts) the name doesn't need to be given in full. If you also use functions from `libblahblah`, you'll add `-lblahblah` to your command line.

# Lecture 2

## Flow Control

### If-else
```c
if (condition) {
  instructions
} else {
  other instructions
}
```

In C, integer values (char, short, int, long) are used instead of boolean data type. `0 = false, other = true`

> Curly brackets not mandatory when conditions applies to a single instruction.

## Inequality
In the ASCII code, uppercase comes before lower case.

### Switch
```c
switch (expression) {
  /*
  Char or integer expression ONLY
  Doesn't work with float/double
  Doesn't work with arrays, including strings
  */
  case value1:
    instructions
    break;
  case value2:
    ...
  default:
    instructions
    break;
  /*
  As in Java, break exits the switch;
  without break, you fall through..
  */
}
```

### While
```c
while (condition) {
  instructions
}
```

```c
do{
  instructions
} while(condition)
```

### For
```c
for (initialization; condition; increment) {
  instructions
}
```
> In tradiJonal C, where usually all variables, even loop variables, are declared at the beginning of a function. Java behaviour is allowed in C99, which borrows it from Java.

## Command Line Parameters

```c
int main(int argc, char *argv[]) {
  /*
  argc is always at least 1,
  in C the first parameter contains the name of the program
  */
}
```

## Error management in C
`int scanf(const char *restrict format, ...);`
It returns the number of items assigned.

### Initialization

> Some C compilers initialize bytes to 0. Others don't.

```c
#include <stdio.h>
int main() {
  printf("Enter an integer: ");
  if (scanf("%d", &n) == 1) {
    printf("The square of %d is %d\n", n, n * n);
  } else{
    printf("An integer was expected.\n");
  }
  return 0;
}
```

## Functions
> As C has no classes, no objects and no methods, C functions are similar to static functions in Java, and aren't attached to any particular variable.

**No overloading.**
> In C (NOT in C++) functions must uniquely be identified by their NAME.

> Functions must be declared before being used.

Two options
1. Define every function before you call it.
2. You put at the beginning of the file function prototypes that are just return type, name and parameters (no function body).

```c
#include

#include "func.h"

#define

code of functions

// Order doesn't matter

main()
```

`#include <filename.h>` looks for system header file at "well known places"

`#include "filename.h"` looks for file in the current
directory

### C Standard Library
Functions that only require a header file.

### Input/Output Functions

Three default "streams"
1. stdin
2. stdout
3. stderr

#### Unix (Linux) "pipe"
`my_program1 | my_program2` Turn the output of one program into the input of another program.

> Most "char" functions actually work with "int" (4-byte) variables that are truncated when assigned to a "char" (1-byte) variable.

```c
c = getchar();
c = fgetc(stdin);

putchar(c);
fputc(c, stdout);
```

#### fgets
For reading lines of text, use fgets() that loads data into an array the maximum size of which is provided. fgets() also loads end-of-line characters.

DON'T USE gets(). If you read more than what the array can store, you'll **corrupt memory**.

`char *fgets(char *str, int size, stdin)`

`gets(str)`

`int fputs(char *str, stream)` *

`int puts(str)` appends `\n` to the output **stdout** *

\* Return 0 if OK, EOF if error.

`scanf(format, &var)`

`printf(format, ...)` **stdout**

`fprintf(stream, format, ...)`

### Classification of characters
`#include <ctype.h>`

It contains functions (and macros) to test characters.

`int issomething(int c)`

- Returns zero if the character isn't a "something".
- Returns something different from zero if it is a "something".

![issomething](midterm/ctype.png)

`int tolower(int c);`

`int toupper(int c);`

> There isn't in standard C any funcJon to change the case of a full string (it's very easy to write).

### String manipulation

```c
#include <string.h>
```

`int strlen(char *string);` Starts from the pointer passed and moves on, counJng chars unJl one encounters \0.

#### Unsafe basic copy/concat functions
`char *strcpy (char *dest, char *src)`

Starts at dest and copies what starts at src until `\0` is met.

`char *strcat(char *dest, const char *src)`

Starts at dest and moves on until one encounters `\0`, then copies what starts at src until `\0` is met.

**NO BOUNDARY CHECKING** Overflow. Possible memory corruption.

#### Limits to n characters at most
`char *strncpy(char *string1, char *string2, int n)`

`char *strncat(char *dest, const char *src, int n)`

**strcmp**

`int strcmp(char *string1, char *string2);`

`int strncmp(char *string1, char *string2, int n);`

- Returns 0 if equal.
- <0 is string1 comes alphabetically before string2
- \>0 is the reverse is true

> Both strcmp() and strncmp() are safe if strings are terminated with `\0`.

**Ignore case**

`int strcasecmp(char *string1, char *string2);`

`int strncasecmp(char *string1, char *string2, int n);`

**Search strings**

`char *strchr(char *string, int c);` Returns NULL if nothing found.

`char *strrchr(char *string, int c);` Searches from the end.

`char *strstr(char *string, char *substring);`

`char *strtok(char *string, char *separators);`

## Chinese Characters
`#include <wchar.h>`

wchar_t is a type that extends char and handles multi-byte
characters.

wide char = character stored on several bytes

`fwprintf()`
`fgetws()`
`wcslen()`
`wcscpy()`

`setlocale(LC_ALL, "zh_CN.UTF-8");`

### Unicode
4-byte (provision for 6) codepoint

# Lecture 3

### GB2312
Succeeded by GBK

GB2312/GBK can encode close to 9,000 characters on two bytes.

### UTF-8
In UTF-8 (most used on the web) 1 to four characters can be used. The first bit(s) of the first byte tells how many bytes compose the character. Continuation bytes always have the left-most bit set to 1.

- 1 byte for basic Latin
- 2 bytes for Europe, Middle Ease
- 3 bytes for Asia
- 4 bytes for weird languages

> It's not as space-efficient as specialized encoding, but it's compatible with most of what pre-existed, the source code of computer programs in particular.

### String conversion
`#include <stdlib.h>`

Old fashioned functions

`int atoi(char *str);` `long atol(char *str);` `doubleatof(char*str);`

Better to use `strtol()` `strtod()`

## Error Handling
`#include <errno.h>`

`int errno` Global variable

Set by all system calls - reset to 0 by all successful system calls

`char *strerror(int errnum )`

Returns the text of the associated
error message

`perror("your message" + strerror(errno));`

## Time functions (the simplest ones)

`#include <time.h>`

`time_t clock;` "time type" (integer)

Dates are stored as the number of seconds since the "epoch"

> **epoch**: January 1st, 1970, 00:00:00

`clock = time(NULL);`
current day and time

`printf("%s", ctime(&clock));`
carriage return `\n` included in what `ctime()` returns

```c
#include <stdio.h>
#include <time.h>
int main() {
  time_t clock;
  clock = (time_t)0;
  printf("%s", ctime(&clock));
  return 0;
}
```

## `random()`


`#include <stdlib.h>`

`long random(void)` means "no parameter"

`srandom(unsigned long seed)`

### Random number between a and b
`num = (data type)(a + (b – a) * random() / (double)RAND_MAX);`

### Random integer between 0 and n - 1
`num = random() % n;`

## Localization

`#include <locale.h>`

`setlocale(LC_ALL, "zh_CN.UTF-8");`

> It affects some time functions (because date formats differ by country), but not ctime().








...
