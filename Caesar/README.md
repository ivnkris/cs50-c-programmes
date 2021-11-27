# Caesar

## Description

This is a programme that encrypts messages using Caesar's cipher.

## Usage

Compile the programme using Clang or any other preferred compilers. Use the following command with the CS50 library:

```
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    caesar.c  -lcrypt -lcs50 -lm -o caesar
```

CS50 library available from here: https://cs50.readthedocs.io/libraries/cs50/c/

Run the programme with the following command-line arguments:

```
./caesar <KEY>
```

For example:

```
./caesar 3
```
