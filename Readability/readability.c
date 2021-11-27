#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
int count_readability_score(int letters, int words, int sentences);

int main(void)
{
    // Get some text from the user
    string text = get_string("Text: ");

    // Count the letters in the text
    int letters = count_letters(text);

    // Count the words in the text
    int words = 0;
    // If text isn't empty start word count from 1
    if (letters > 0)
    {
        words = 1;
    }
    words += count_words(text);

    // Count the sentences in the text
    int sentences = count_sentences(text);

    // Count readability score
    int readability_score = count_readability_score(letters, words, sentences);

    // Print readability grade
    if (readability_score < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readability_score > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", readability_score);
    }
}

int count_letters(string s)
{
    int letters = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If the character is either an uppercase or lowercase letter, increase the count
        if (islower(s[i]) || isupper(s[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string s)
{
    int words = 0;
    // Iterate through text and if found a space count it as word
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string s)
{
    int sentences = 0;
    // Iterate through text and if found . or ! or ? count it as sentence
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int count_readability_score(int letters, int words, int sentences)
{
    double L = (float) letters / (float) words * 100;
    double S = (float) sentences / (float) words * 100;
    // Calculate Coleman-Liau index
    double index = 0.0588 * L - 0.296 * S - 15.8;
    // Round to nearest integer
    int score = roundf(index);

    return score;
}