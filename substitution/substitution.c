#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int encipher_upper_index(string x, int y, string s);
int encipher_lower_index(string x, int y, string s);

int main(int argc, string argv[])
{
    int i; //indicator
    string s = argv[1];
    int len = strlen(s);
    printf("%i", argc);

    //confirm enter correct
    /*
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    */

    //confirm the number of the string
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
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

    //confirm non repeat
    for (i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            //printf("%c, %c\n", s[j], s[i]);
            if (s[j] == s[i])
            {
                //printf("%i, %i\n", i, j);
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    //printf("%s\n", s);

    //all good
    //mapping alphabeta
    string ans = get_string("plaintext: ");
    int len_ans = strlen(ans);

    //sandox
    char a = 'a';
    int x = 65;
    //printf("%c, %s, %i\n", x, ans, (int) ans);

    //encipher
    printf("ciphertext: ");
    for (i = 0; i < len_ans; i++)
    {

        //printf("%i, %i, %i, %c, ", i, (int) isupper(ans[i]), (int) islower(ans[i]), ans[i]);
        if (isupper(ans[i]))
        {
            //printf("%c", s[encipher_upper_index(ans, i)]);
            printf("%c", encipher_upper_index(ans, i, s));
        }

        else if (islower(ans[i]))
        {
            //printf("%c", s[encipher_lower_index(ans, i)]);
            printf("%c", encipher_lower_index(ans, i, s));
        }

        else
        {
            printf("%c", ans[i]);
        }
        //printf("\n");


        /*
        if (isupper(ans[i]))
        {

        }
        */
    }
    printf("\n");

}

int encipher_upper_index(string x, int y, string s)
{
    int ki = (int) x[y] - 65;
    char z = toupper(s[ki]);
    return z;
}

int encipher_lower_index(string x, int y, string s)
{
    int ki = (int) x[y] - 97;
    char z = tolower(s[ki]);
    return z;
}