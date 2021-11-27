#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if user has given exectly one command-line arguments and if not return with error code 1
    if (!argv[1] || argv[2])
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if all characters in the command-line arguments are digits and if not return with error code 1
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if ((char) argv[1][i] < 49  || (char) argv[1][i] > 57)
        {
            printf("Key needs to be a positive integer\n");
            return 1;
        }
    }

    // Convert command-line argument into cypher key
    int key = atoi(argv[1]);
    key = key % 26;

    // Prompt user to enter some plaintext
    string plaintext = get_string("plaintext: ");

    // Convert plaintext into ciphertext and print cyphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]))
        {
            int shift = (int) plaintext[i] + key;
            if (shift > 122)
            {
                shift -= 26;
            }
            printf("%c", (char) shift);
        }
        else if (isupper(plaintext[i]))
        {
            int shift = (int) plaintext[i] + key;
            if (shift > 90)
            {
                shift -= 26;
            }
            printf("%c", (char) shift);
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }

    // Print new line and return with return code 0
    printf("\n");
    return 0;
}