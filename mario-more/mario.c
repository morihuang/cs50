#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ans_layer = get_int("Set layer level of a pyramid: \n");
    for(i=0, i < ans_layer, i++):
    {
        for (j=0, j < ans_layer, j++):
        {
            printf("#")
            printf("  ")
            printf("#")
        }
    }
}