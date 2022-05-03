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
    printf("%li\n", ans);

    //invalid test - Luhn’s Algorithm
    int j;
    long t1_ans = 0;
    long t2_ans = 0;
    long t3_ans = 0;
    long fd_ans;
    long x_ans = ans;


    for (j = 1; j < i; j += 2)
    {
        //even digit * 2
        t1_ans = (x_ans / 10^j) % 10 * 2;
        //printf("%li, %li\n", x_ans, t_ans);

        //odd digit
        t2_ans = (x_ans / 10^j-1) % 10;

        t3_ans += t1_ans + t2_ans;
    }
    printf("%li, %li, %li\n", t1_ans, t2_ans, t3_ans);
    if (t3_ans % 10 == 0)
    {
        fd_ans = ans / 10^(i-2);
        if (fd_ans == 34 || fd_ans == 37)
        {
            printf("AMEX\n");
        }
        else if (fd_ans >= 51 && fd_ans <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (fd_ans == 4)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }









}