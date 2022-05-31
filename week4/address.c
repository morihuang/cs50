#include <cs50.h>
#include <stdio.h>

/*
int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", n);
    printf("%p\n", &n);
    printf("%p\n", p);
}
*/


int main(void)
{

    /*
    //#1
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", n);
    printf("%i\n", *p);
    */

    /*
    //#2
    string s = "HI!";
    //char c = s[0];
    char *p = &s[0];
    //char *p = &c;
    //char *s = "HI!";

    printf("%p\n", p);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%p\n", &s[4]);
    printf("%p\n", &s[5]);
    */

    //#3
    char *s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", *s);

}