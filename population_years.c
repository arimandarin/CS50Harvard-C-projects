  
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        // Prompt user for a starting number of population biggetr or equal than 9
        n = get_int("Enter number of starting population: ");
    }
    while (n < 9);

    //printf("%i\n", n);

    int m;
    do
    {
        // Prompt user for a starting number of population bigget or equal than 9
        m = get_int("Enter number of ending population: ");
    }
    while (m < n);

    //printf("%i\n", m);

    // declare variable
    int years = 0;

    do
    {
        // formula
        n = n + (n / 3) - (n / 4);
        // increase years by one every loop until the starting reach the ending population
        years++;
    }
    while (n < m);

    // print years to increase from starting to ending population
    printf("Years: %i\n", years);

}
