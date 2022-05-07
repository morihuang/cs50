#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    string ans = get_string ("Text: ");
    //printf("%s\n", ans);
    printf("%i letters.\n", count_letters(ans));
    printf("%i words.\n", count_words(ans));
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
    int j = 1;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isspace(text[i]))
        {
            j++;
        }
    }
    return j;
}