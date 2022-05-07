#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float a, float b, float c);

int main(void)
{
    int a = get_int("The length of 1st side: \n");
    int b = get_int("The length of 2nd side: \n");
    int c = get_int("The length of 3rd side: \n");

    int x = valid_triangle(a, b, c);
    if (x != 0)
    {
        printf("valid!\n");
    }
    else
    {
        printf("not valid!\n");
    }


}

bool valid_triangle(float a, float b, float c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        return false;
    }
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        return false;
    }
    return true;
}