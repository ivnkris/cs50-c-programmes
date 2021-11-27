#include <cs50.h>
#include <stdio.h>

void printBlocks(int n);
void printSpaces(int n);

int main(void) 
{
    // Prompt for height
    int height;
    do 
    {
        height = get_int("How tall should the pyramid be? (between 1 and 8)\n ");
    }
    while (1 > height || height > 8);
    
    printf("Height: %i\n", height);
    
    // Build pyramid
    int blocks = 1;
    int spaces = height - 1;
    for (int i = 0; i < height; i++)
    {
        printSpaces(spaces);
        printBlocks(blocks);
        printf("\n");
        spaces--;
        blocks++;
    }
}

// Print pyramid blocks
void printBlocks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

// Print spaces to right align pyramid
void printSpaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}