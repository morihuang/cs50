#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int i; //indicator
    string s = argv[1];
    int len = strlen(s);

    //confirm the number of the string
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        //return 1;
    }

    //confirm all alphbets
    for (i = 0; i < len; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    //confirm enter correct
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //confirm non repeat
    for (i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            //printf("%c, %c\n", s[j], s[i]);
            if (s[j] == s[i])
            {
                printf("%i, %i\n", i, j);
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    printf("%s\n", s);

    //all good
    //mapping alphabeta
    string ans = get_string(")

    for (i = 0; i < len; i++)
    {

    }

}