# Filter

## Description

This is a programme that applies filters to bitmap(.bmp) images. The available flags are the following:
-g grayscale
-s sepia
-r reflect
-b blur

## Usage

Compile the programme using Clang or any other preferred compilers. Use the following command with the CS50 library:

```
clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm -o filter filter.c helpers.c
```

CS50 library available from here: https://cs50.readthedocs.io/libraries/cs50/c/

Run the programme with the following command-line arguments:

```
./filter <FILTER_FLAG> <INPUT_FILE> <OUTPUT_FILE>
```

For example:

```
./filter -g infile.bmp outfile.bmp
./filter -s infile.bmp outfile.bmp
./filter -r infile.bmp outfile.bmp
./filter -b infile.bmp outfile.bmp
```
