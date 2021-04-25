#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get integer between 1 and 8 from user
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Print out the pyramid
    for (int i = 0; i < n; i++)
    {
        // Print out blank spaces to move the hashes to the right
        for (int k = 1; k < n - i; k++)
        {
            printf(" ");
        }
        // Print out the hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
