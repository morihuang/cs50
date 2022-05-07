#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
    return n;
}