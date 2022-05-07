#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int len = strlen(argv[1]);
    //confirm the number of the string
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //confirm all alphbets
    if (isalpha(argv[1]) == 0)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    //confirm non repeat
    if (argc != 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


    //
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("%s, %s\n", argv[1][j], argv[1][i]);
            if (argv[1][j] == argv[1][i])
            {
                printf("Key must not contain repeated characters.\n");
                break;
            }
        }
    }

}