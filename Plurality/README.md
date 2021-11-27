# Plurality

## Description

This is a programme that runs a plurality election.

## Usage

Compile the programme using Clang or any other preferred compilers. Use the following command with the CS50 library:

```
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    plurality.c  -lcrypt -lcs50 -lm -o plurality
```

CS50 library available from here: https://cs50.readthedocs.io/libraries/cs50/c/

Run the programme with the following command-line arguments:

```
./plurality <CANDIDATE1 CANDIDATE2 ETC...>
```

For example:

```
./plurality Alice Bob Charlie
```
