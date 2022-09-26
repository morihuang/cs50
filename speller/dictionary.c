// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return 1;
    }

    // read words into an array
    char *tmp_word[sizeof(dictionary)];
    char *check;

    fscanf(file, "%s", *tmp_word);
    /*while (strcmp(check, "EOF") == 0)
    {
        check =
    }*/

    // allocate memory to new node
    int index = 0;

    for (int i = 0; i < sizeof(tmp_word); i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 0;
        }

        strcpy(n->word, tmp_word[i]);

        index = hash(n->word);

        if (table[index]->next == NULL)
        {
            n->next = NULL;
            table[index] = n;
        }
        else
        {
            n->next = table[index]->next;
            table[index]->next = n;
        }

    }


    //char *dict[];
    //fread(&dict, sizeof(char), 1, file);
    /*
    for (i = 0; i <  N + 1; i++)
    {
        strcpy(n->word, dict[i]);
        n->next = NULL;
        table[] = n;
    }
    */





    return false;
}



// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    check_letter = tolower(char *word)
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
