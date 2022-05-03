#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*
    long ans;
    do
    {
        ans = get_long("Number: ");
    }
    while (ans < 1e12 && 1e13 <= ans && ans < 1e14 && ans > 1e16);

    printf("%li\n", ans);

*/

    long ans = get_long("Number: ");

    //invalid test - digit
    int i = 1;
    long d = ans;
    while (d > 10)
    {
        d = d / 10;
        i++;
    }
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
    }

    //invalid test - Luhn’s Algorithm
    int j;
    long t_ans = 0;
    long x_ans = ans;
    while (x_ans >= 1)
    {
        x_ans /= 10;
        t_ans += x_ans % 10 * 2;
        printf("%li, %li\n", x_ans, t_ans);
    }




}