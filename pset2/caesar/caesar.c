#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Key needs to be a positive integer!\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");

    for (int i = 0; i < strlen(plaintext); i ++)
    {
        if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'a' + key) % 26 + 'a');
        }
        else if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'A' + key) % 26 + 'A');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
}