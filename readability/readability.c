#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
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
    int j = 0;
    for (int i = 0; i <= n; i++)
    {
        if (isalpha(text[i]))
        {
            j++;
        }
    }
    return j;
}

int count_words(string text)
{
    for(int i = 0, n = strlen(text); )
}