# Recover

## Description

This is a programme that recovers lost data from a DSLR camera's memory card.

## Usage

Compile the programme using Clang or any other preferred compilers. Use the following command with the CS50 library:

```
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    recover.c  -lcrypt -lcs50 -lm -o recover
```

CS50 library available from here: https://cs50.readthedocs.io/libraries/cs50/c/

Run the programme with the following command-line arguments:

```
./recover <MEMORY_CARD_FORENSIC_IMAGE_FILE>
```

For example:

```
./recover card.raw
```
