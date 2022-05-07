#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    string s = argv[1];
    int len = strlen(s);

    //printf("%s, %i\n", s, len);
    //printf("%s, %i, %i\n", s, len, ab);
    /*for (int i = 0; i < len; i++)
    {
        if (isalpha(s[i]))
        {
        printf("yes!\n");
        }
    }*/

    //confirm the number of the string

    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        //return 1;
    }

    //confirm all alphbets
    for (int i = 0; i < len; i++)
    {
        //printf("%c\n", s[i]);
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
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            //printf("%c, %c\n", s[j], s[i]);
            if (s[j] == s[i])
            {
                printf("%i, %i\n", i, j);
                printf("Key must not contain repeated characters.\n");
                return 1;
                //break;
            }
        }
    }
    printf("%s\n", s);

    return 0;

}