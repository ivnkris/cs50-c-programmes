#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int population;
    do
    {
        population = get_int("Start size: \n ");
    }
    while (population < 9);

    // Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: \n ");
    }
    while (endSize < population);

    // Calculate number of years until we reach threshold
    int years = 0;
    while (population < endSize)
    {
        population = population + (population / 3) - (population / 4);
        years++;
    }

    // Print number of years
    printf("Years: %i\n ", years);
}