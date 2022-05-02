#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long ans;
    do
    {
        ans = get_long("Number: ");
    }
    while (ans < (1e13) || ans > (1e16));

    
}