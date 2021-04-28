# include <stdio.h>
# include <cs50.h>

int main(void)
{
    //declaring variables
    int height;
    int spaces;
    int dashes;

    do
    {

        height = get_int("Height: ");
    }
    while (height <= 0 || height >= 8);
    //loop for the rows
    for (int i = 0; i <= height; i++)
    {
        //loop for the spaces and dashes per row
        for (spaces = (height - i); spaces >= 0; spaces--)
        {
            printf(" ");
        }
        for (dashes = 1; dashes <= i; dashes++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
