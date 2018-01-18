# Final Review

## Dynamic Memory

### `strdup()`

`char * strdup(const char *str1);`

Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by `str1`.

The returned pointer must be passed to `free()` to avoid a memory leak.

If an error occurs, a `null` pointer is returned and `errno` may be set.

### `strndup()`

`char *strndup(const char *str, size_t size);`

Returns a pointer to a null-terminated byte string, which contains copies of at most `size` bytes from the string pointed to by `str`.

If the `null` terminator is not encountered in the first `size` bytes, it is added to the duplicated string.

## String

### `strncpy()`

`char *strncpy( char *restrict dest, const char *restrict src, size_t count );`

Copies at most `count` characters of the character array pointed to by `src` (including the terminating `null` character, but not any of the characters that follow the `null` character) to character array pointed to by `dest`.

If `count` is reached before the entire array `src` was copied, the resulting character array is not null-terminated.

If, after copying the terminating `null` character from `src`, `count` is not reached, additional `null` characters are written to dest until the total of `count` characters have been written.

The behavior is undefined if the character arrays overlap, if either `dest` or `src` is not a pointer to a character array (including if `dest` or `src` is a null pointer), if the size of the array pointed to by `dest` is less than `count`, or if the size of the array pointed to by `src` is less than `count` and it does not contain a `null` character.

### `strcat()`

`char *strcat( char *restrict dest, const char *restrict src );`

Appends a copy of the null-terminated byte string pointed to by `src` to the end of the null-terminated byte string pointed to by `dest`. The character `src[0]` replaces the `null` terminator at the end of dest. The resulting byte string is null-terminated.

The behavior is undefined if the destination array is not large enough for the contents of both `src` and `dest` and the terminating `null` character.

The behavior is undefined if the strings overlap.

The behavior is undefined if either `dest` or `src` is not a pointer to a null-terminated byte string.

### `strncat()`

`char *strncat( char *restrict dest, const char *restrict src, size_t count );`

Appends at most `count` characters from the character array pointed to by `src`, stopping if the `null` character is found, to the end of the null-terminated byte string pointed to by `dest`. The character `src[0]` replaces the `null` terminator at the end of `dest`. The terminating `null` character is always appended in the end (so the maximum number of bytes the function may write is `count+1`).

The behavior is undefined if the destination array does not have enough space for the contents of both `dest` and the first count characters of `src`, plus the terminating `null` character. The behavior is undefined if the source and destination objects overlap. The behavior is undefined if either `dest` is not a pointer to a null-terminated byte string or `src` is not a pointer to a character array.

### `strlen()`

`size_t strlen( const char *str );`

Returns the length of the given null-terminated byte string, that is, the number of characters in a character array whose first element is pointed to by `str` up to and not including the first null character.

The behavior is undefined if `str` is not a pointer to a null-terminated byte string.

### `strcmp()`

`int strcmp( const char *lhs, const char *rhs );`

Compares two null-terminated byte strings lexicographically.

The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as unsigned char) that differ in the strings being compared.

The behavior is undefined if `lhs` or `rhs` are not pointers to null-terminated byte strings.

### `strncmp()`

`int strncmp( const char *lhs, const char *rhs, size_t count );`

Compares at most `count` characters of two possibly null-terminated arrays. The comparison is done lexicographically.

The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as `unsigned char`) that differ in the arrays being compared.

The behavior is undefined when access occurs past the end of either array `lhs` or `rhs`. The behavior is undefined when either `lhs` or `rhs` is the null pointer.

### `strtok()`

`char *strtok( char *restrict str, const char *restrict delim );`

Finds the next token in a null-terminated byte string pointed to by str. The separator characters are identified by null-terminated byte string pointed to by delim.

This function is designed to be called multiples times to obtain successive tokens from the same string.

If str != NULL, the call is treated as the first call to strtok for this particular string. The function searches for the first character which is not contained in delim.

- If no such character was found, there are no tokens in str at all, and the function returns a null pointer.
- If such character was found, it is the beginning of the token. The function then searches from that point on for the first character that is contained in delim.
  - If no such character was found, str has only one token, and future calls to strtok will return a null pointer.
  - If such character was found, it is replaced by the null character '\0' and the pointer to the following character is stored in a static location for subsequent invocations.
- The function then returns the pointer to the beginning of the token.

If str == NULL, the call is treated as a subsequent calls to strtok: the function continues from where it left in previous invocation. The behavior is the same as if the previously stored pointer is passed as str.

The behavior is undefined if either str or delim is not a pointer to a null-terminated byte string.

### `strstr()`

`char *strstr( const char* str, const char* substr );`

Finds the first occurrence of the null-terminated byte string pointed to by `substr` in the null-terminated byte string pointed to by `str`. The terminating `null` characters are not compared.

The behavior is undefined if either `str` or `substr` is not a pointer to a null-terminated byte string.

### `strchr()`

`char *strchr( const char *str, int ch );`

Finds the first occurrence of `ch` (after conversion to char as if by `(char)ch`) in the null-terminated byte string pointed to by `str` (each character interpreted as unsigned char).

The terminating `null` character is considered to be a part of the string and can be found when searching for `'\0'`.

The behavior is undefined if `str` is not a pointer to a null-terminated byte string.

## Zombie Process

On Unix and Unix-like computer operating systems, a zombie process or defunct process is a process that has completed execution (via the exit system call) but still has an entry in the process table: it is a process in the "Terminated state".

This occurs for child processes, where the entry is still needed to allow the parent process to read its child's exit status: once the exit status is read via the wait system call, the zombie's entry is removed from the process table and it is said to be "reaped".

A child process always first becomes a zombie before being removed from the resource table. In most cases, under normal system operation zombies are immediately waited on by their parent and then reaped by the system – processes that stay zombies for a long time are generally an error and cause a resource leak.

## `new` and `delete` expressions

## Inheritance

## Method

- Overloading
- Overriding
- Hiding

## Constructors

## Template











...
