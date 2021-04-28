#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int cents;
//checking negative values
    do
    {
        float dollars = get_float("Change owed: ");
        cents = round(dollars * 100);
    }
    while (cents <= 0);
// Doing the logic for each type of coins
    int quart = cents / 25;
    int dim = (cents % 25) / 10;
    int nick = ((cents % 25) % 10) / 5;
    int penny = ((cents % 25) % 10) % 5;
// printing the number of coins
    printf("%d\n", quart + dim + nick + penny);
}
