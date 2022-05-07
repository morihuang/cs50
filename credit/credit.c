#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long ans = get_long("Number: ");

    //invalid test - digit
    int i = 1;
    long d = ans;
    while (d > 10)
    {
        d = d / 10;
        i++;
    }

    printf("%i\n", i);

    //invalid test - Luhn’s Algorithm
    int j;
    long t1_ans = 0;
    long t11_ans = 0;
    long t2_ans = 0;
    long t3_ans = 0;
    long t4_ans = 0;
    long fd1_ans;
    long fd2_ans;
    long x_ans = ans;


    for (j = 1; j <= i; j += 2)
    {
        //even digit * 2
        t11_ans = (x_ans / (long) pow(10, j)) % 10;
        t11_ans *= 2;
        if (t11_ans > 9)
        {
            t11_ans = (t11_ans % 10) + ((t11_ans / 10) % 10);
        }
        t1_ans += t11_ans;

        //printf("%li, %li\n", x_ans, t_ans);

        //odd digit
        t2_ans += (x_ans / (long) pow(10, j - 1)) % 10;

        //t4_ans = t1_ans * 2 + t2_ans;
        //printf("%li, %li\n", t1_ans, t2_ans);
    }
    t3_ans = t1_ans + t2_ans;
    printf("%li\n", t3_ans);

    if ((i == 13 || i == 15 || i == 16) && t3_ans % 10 == 0)
    {
        fd1_ans = ans / pow(10, i - 1);
        fd2_ans = ans / pow(10, i - 2);
        //printf("%li\n", fd_ans);
        if (fd2_ans == 34 || fd2_ans == 37)
        {
            printf("AMEX\n");
        }
        else if (fd2_ans >= 51 && fd2_ans <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (fd1_ans == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}