// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// hash table buckets aka. threshold of the alphabet needed
int t = 2;
const unsigned int N = 676;
int count_words = 0;

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
        printf("no such file.");
        return false;
    }
    // read words into an array
    char tmp_word[200000];
    int check_end = 0;
    bool ans = false;
    while (check_end != EOF)
    {
        check_end = fscanf(file, "%s", tmp_word);
        count_words++;
    }

    // arrange data into hash table
    int index = 0;
    for (int i = 0; i < sizeof(tmp_word); i++)
    {
        // allocate memory to new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 0;
        }
        // copy word to a temp array
        strcpy(n->word, &tmp_word[i]);

        // ask for the index in a hash
        index = hash(n->word);

        // distribute in the hash table according to the situation of the table
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
    fclose(file);
    return 1;
}

// Hashes word to a number, should be 0 to N-1 indices
unsigned int hash(const char *word) // an integer that will be negative representing which index in the hash table u will use
{
    // TODO: Improve this hash function
    // to iterate through the input word and find the index
    int count = 0;
    for (int i = 0; i < t; i++)
    {
        count += (tolower(word[i]) - 'a') * pow(26, t-i-1);
    }
    return count;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count_words;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int i_input = hash(word); // get the index of input word
    int result = 1; // check the comparison result
    // char *ref_word = table[i_input]->word; // get the word
    node *pter = table[i_input]->next; // a temp pter to navigate through the linked list

    // compare each words in the linked list
    while (pter->next != NULL)
    //for (int i = 0; i < t; i++) // for text
    {
        result = strcasecmp(word, pter->word);
        if (result != 0)
        {
            pter = pter->next;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i]->next;
        free(table[i]);
        table[i] = tmp;
    }
    return true;
}



