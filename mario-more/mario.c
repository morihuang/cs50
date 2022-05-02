#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ans_layer = get_int("Height: \n");
    if(ans_layer > 1 || ans_layer < 8):
    {
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
    else:
        int ans_layer = get_int("Height: \n");

}