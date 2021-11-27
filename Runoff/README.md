# Runoff

## Description

This is a programme that runs a runoff election.

## Usage

Compile the programme using Clang or any other preferred compilers. Use the following command with the CS50 library:

```
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    runoff.c  -lcrypt -lcs50 -lm -o runoff
```

CS50 library available from here: https://cs50.readthedocs.io/libraries/cs50/c/

Run the programme with the following command-line arguments:

```
./runoff <CANDIDATE1 CANDIDATE2 ETC...>
```

For example:

```
./runoff Alice Bob Charlie
```
