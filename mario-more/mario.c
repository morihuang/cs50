#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ans_layer;
    do
    {
        ans_layer = get_int("Height: \n");
    }
    while (ans_layer < 1 || ans_layer > 8);


    int i, j, k, l, m;
    while (i=0, i < ans_layer, i++)
    {
        while (j=0, j < ans_layer, j++)
        {
            //spaces
            while (k=0, k < ans_layer-1, k++)
            {
                printf(" ");
            }

            //#
            while (l=0, l < i, l++)
            {
                printf("#");
            }

            //gap
            printf("  ");

            //#
            while (m=0, m < i, m++)
            {
                printf("#\n");
            }


        }
    }
}