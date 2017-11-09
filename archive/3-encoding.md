## Localization

```c
#include <locale.h>
```

- Pointers
- Structures
- Files

## Pointers

no need to know the exact memory location

**& returns the address**

1. How many bytes?
2. How to interpret (encoding)?

### Pointer declaration
```c
data_type *pointer_name
```

```c
int my_var = 4;
int *my_ptr;
my_ptr = &my_var;
```

Declaring a pointer only reserves memory for the pointer.

```c
int my_array[25];
```

Declares two things
1. Room to store 25 integers.
2. A pointer to the first one.

```c
sizeof()
```

**An uninitialized pointer could hit memory anywhere.**

### Dereferencing

***operator**

```c
int my_var = 4;
int *my_ptr;
my_ptr = &my_var;
printf("%d\n", *my_ptr);
```
```c
int my_var = 4;
int *my_ptr = &my_var;
printf("%d\n", *my_ptr);
```

### Pointer arithmetic

```c
p++; // Increments p
*p++; // Returns the value then increases p
(*p)++; // Increases by one what p points to
```

```c
char *p = NULL;
char str[] = "Shenzhen";
p = str + 4;
printf("%s\n", p);
```

```c
char str[15] = "Shenzhen"; // Reserve 15 bytes
```

### Arrays of strings
```c
char *string_array[] = {"Welcome", "Shenzhen"};
```

```c
int main(int argc, char *argv[]){
  // Passed to the program by the system
  // argc >= 1
  return 0;
}
```

**echo.c**

**getopt() function**

## struct

```c
// a variable declaration
struct{
  char place_name[NAME_LEN];
  double latitude;
  double longitude;
} my_place;
// (nameless) data type

struct{
  char place_name[NAME_LEN];
  double latitude;
  double longitude;
} my_place[PLACE_COUNT];

strncpy(my_place.place_name, "Shenzhen", NAME_LEN);
my_place.latitude = 22.25;
my_place.longitude = 114.1;
```
**No private attributes in C.**

### Naming a structure

```c
struct my_struct{
  char place_name[NAME_LEN];
  double latitude;
  double longitude;
};

typedef struct my_struct{
  char place_name[NAME_LEN];
  double latitude;
  double longitude;
} PLACE_T;
```

**typedef**

**Structures aren't necessarily packed.**

### Alignment
**depends on the architecture.**

### Dereferencing
```c
ptr->place_name
// Dot notation refers to variable.
// Arrow notation refers to pointer to a structure
```

structc can be nested.

**whichday.c**
