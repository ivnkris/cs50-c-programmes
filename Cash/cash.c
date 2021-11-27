#include <cs50.h>
#include <stdio.h>
#include <math.h>

int getQuarters(float n);
int getDimes(float n);
int getNickles(float n);
int getPennies(float n);

int cents;

int main(void)
{
    float change;
    // Prompt for change
    do 
    {
        change = get_float("Change owed: ");
    }
    while (0 > change);
    
    cents = round(change * 100);
    
    int numberOfCoins = 0;
    
    // Calculate quarters
    numberOfCoins += getQuarters(cents);
    
    // Calculate dimes
    numberOfCoins += getDimes(cents);
    
    // Calculate nickels
    numberOfCoins += getNickles(cents);
    
    // Calculate pennies
    numberOfCoins += getPennies(cents);
   
    // Print number of coins
    printf("%i\n", numberOfCoins);
}

int getQuarters(float n)
{
    int numberOfQuarters = n / 25;
    cents -= numberOfQuarters * 25;
    
    return numberOfQuarters;
}

int getDimes(float n)
{
    int numberOfDimes = n / 10;
    cents -= numberOfDimes * 10;
    
    return numberOfDimes;
}

int getNickles(float n)
{
    int numberOfNickles = n / 5;
    cents -= numberOfNickles * 5;
    
    return numberOfNickles;
}

int getPennies(float n)
{
    int numberOfPennies = n / 1;
    
    return numberOfPennies;
}