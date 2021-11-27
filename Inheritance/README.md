# Inheritance

## Description

This is a programme that randomly calculates blood types within a family tree.

## Usage

Compile the programme using Clang or any other preferred compilers. Use the following command with the CS50 library:

```
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow inheritance.c -lcrypt -lcs50 -lm -o inheritance
```

CS50 library available from here: https://cs50.readthedocs.io/libraries/cs50/c/

Run the programme:

```
./inheritance
```

Example output:

```
Generation 0, blood type BO
    Generation 1, blood type BO
        Generation 2, blood type BB
        Generation 2, blood type OA
    Generation 1, blood type AO
        Generation 2, blood type AB
        Generation 2, blood type OB
```
