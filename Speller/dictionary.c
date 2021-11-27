// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

unsigned int hash_value;

unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    hash_value = hash(word);
    // Access linked list at that index in the hash table
    node *cursor = table[hash_value];
    // Traverse linked list, looking for the word(strcasecmp)
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        
        cursor = cursor->next;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    int c;
    
    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    // Use fopen
    FILE *file = fopen(dictionary, "r");
        
    // Check if return value is null
    if (file == NULL)
    {
        return false;
    }
    
    // Read strings from file one at a time
    // fscanf(file, "%s", word)
    // fscan will return EOF once it reaches end of file
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        // Use malloc
        node *n = malloc(sizeof(node));
        // Check if return value is null
        if (n == NULL)
        {
            return false;
        }
        // Copy word into node using strcpy
        strcpy(n->word, word);
                
        // Hash word to obtain a hash value
        // Use hash function
        // Function takes a string and returns an index
        hash_value = hash(word);
                
        // Insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
        
    fclose(file);
    
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
