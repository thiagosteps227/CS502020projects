#include <stdio.h>
#include <string.h>

#include <math.h>
#include <cs50.h>

int main(void)
{
    string text = get_string("Text: ");

    int countletters = 0;
    int countword = 1;
    int countsentence = 0;


    for (int j = 0; j < strlen(text); j++)
    {
       if ( (text[j] >= 'A' && text[j] <= 'Z') || (text[j] >= 'a' && text[j] <= 'z'))
       {
           countletters++;
       }
       else if (text[j] == ' ')
       {
           countword++;
       }
       else if (text[j] == '.' || text[j] == '!' || text[j] == '?')
       {
           countsentence++;
       }
    }


    float grade = 0.0588 * (100 * (float) countletters / (float) countword) - 0.296 * (100 * (float) countsentence / (float) countword) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}