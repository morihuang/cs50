#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ans_layer;
    do
    {
        ans_layer = get_int("Height: ");
    }
    while (ans_layer < 1 || ans_layer > 8);
    //printf("%i\n", ans_layer);

    int i, j, k, l, m;
    for (i = 0; i < ans_layer; i++)
    {

        //spaces
        for (k = 0; k < ans_layer - i - 1; k++)
        {
            printf(" ");
        }

        //#
        for (l = 0; l < i + 1; l++)
        {
            printf("#");
        }

        //gap
        printf("  ");

        //#
        for (m = 0; m < i + 1; m++)
        {
            printf("#");
        }

        printf("\n");


    }



}