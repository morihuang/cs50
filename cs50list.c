
// Implements a list of numbers with linked list

#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // List of size 0
    node *list = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1; // (*n).number = 1
    n->next = NULL;
    list = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2; // (*n).number = 2;
    n->next = NULL; // (*n).next = NULL;
    list->next = n; // (*list).next = n; pter vs. pter

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n; // *((*list).next).next = n;

    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next) // tmp = (*tmp).next
    {
        printf("%i\n", tmp->number);
    }

    // Free list
    while (list != NULL)
    {
        node *tmp = list->next; // node *tmp = (*list).next; 2 instead of 1, coz (*list).next means next node
        free(list);
        list = tmp;
    }
    return 0;
}

