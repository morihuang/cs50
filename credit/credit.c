#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long ans;
    do
    {
        ans = get_long("Number: ");
    }
    while (ans < 10^13 || ans > 10^16);

}