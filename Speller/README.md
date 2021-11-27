# Speller

## Description

This is a programme that is implementing a hash table to store words of a dictionary in memory and spell-checks the contents of a file.

## Usage

Compile the programme using Clang or any other preferred compilers. Use the following command with the CS50 library:

```
clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o speller.o speller.c
clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o dictionary.o dictionary.c
clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o speller speller.o dictionary.o -lm
```

CS50 library available from here: https://cs50.readthedocs.io/libraries/cs50/c/

Run the programme with the following command-line arguments:

```
./speller <FILE_TO_SPELL_CHECK>
```

For example:

```
./speller texts/lalaland.txt
```
