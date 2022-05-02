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

}