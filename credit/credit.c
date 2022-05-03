#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long ans;
    do
    {
        ans = get_long("Number: ");
    }
    while (ans < 1e12 && 1e13 <= ans && ans < 1e14 && ans > 1e16);

    printf("%li\n", ans);

}