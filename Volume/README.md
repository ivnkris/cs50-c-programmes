# Volume

## Description

This is a programme that changes the volume of a .wav file by a given multiplier.

## Usage

Compile the programme using Clang or any other preferred compilers. Use the following command with the CS50 library:

```
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow volume.c  -lcrypt -lcs50 -lm -o volume
```

CS50 library available from here: https://cs50.readthedocs.io/libraries/cs50/c/

Run the programme with the following command-line arguments:

```
./volume <INPUT_FILENAME> <OUTPUT_FILENAME> <VOLUME_MULTIPLIER>
```

For example:

```
./volume input.wav output.wav 2.0
```
