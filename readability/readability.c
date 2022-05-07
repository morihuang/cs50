#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string ans = get_string ("Text: ");
    printf("%s\n", ans);
    printf("%i letters.\n", count_letters(ans));
}

int count_letters(string text)
{
    int n = strlen(text);
    int j = 0;
    for (int i = 0; i <= n; i++)
    {
        if (isalpha)
        {
            j++;
        }
    }
    printf("%i, %i", n, j);
    n = n - j;
    return n;
}