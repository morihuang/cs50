#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //confirm the number of the string
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }

    //confirm all alphbets
    if (isalpha(argv[1]) == 0)
    {
        printf("Key must only contain alphabetic characters.\n");
    }

    //confirm non repeat
    if ()


}