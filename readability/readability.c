#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string ans = get_string ("Text: ");
    //printf("%s\n", ans);
    int l = count_letters(ans);
    int w = count_words(ans);
    int s = count_sentences(ans);

    //printf("%i letters.\n", l);
    //printf("%i words.\n", w);
    //printf("%i sentences. \n", s);

    float L = l / w * 100;
    float S = s / w * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    //float x = 0.0588 * L - 0.296 * S - 15.8;
    //printf("%f\n", x);
    if (index >= 16)
    {
        printf("Grade 16+");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade: %i\n", index);
    }

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

int count_sentences(string text)
{
    int j = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            j++;
        }
    }
    return j;
}