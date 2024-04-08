// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int sizeDic = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int value = hash(word);
    node *n = table[value];
    for (node *swap = n; swap != NULL; swap = swap->next)
    {
        if (strcasecmp(swap->word, word) == 0)
            return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int i = 0;
    while (word[i] != 0)
        i++;
    if (i > N)
    {
        if (i % 2 == 0)
            return (i / 2);
        else
            return ((i + 1) / 2);
    }
    return i;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *src = fopen(dictionary, "r");
    if (src == NULL)
    {
        printf("Error! Can't open.%s\n", dictionary);
        return false;
    }
    char actualWord[LENGTH + 1];
    while (fscanf(src, "%s", actualWord) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return false;
        strcpy(n->word, actualWord);
        int value = hash(actualWord);
        n->next = table[value];
        table[value] = n;
        sizeDic++;
    }
    fclose(src);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return sizeDic;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *n = NULL;
    node *swap = NULL;
    for (int i = 0; i < N; i++)
    {
        n = table[i];
        while (n != NULL)
        {
            swap = n;
            n = n->next;
            free(swap);
        }
    }
    return true;
}
