#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card;

    int count = 0; // Length of card
    int checksum = 0; // Luhn's algorithm

    do
    {
        card = get_long("Enter card's number: ");
    }
    while (card < 0); // If card < 0, it will ask again for the card's number

    long numbers = card; // Copy card's number in another variable to check the length

    while (numbers > 0)
    {
        numbers /= 10;
        count++;
    }


    if (count < 13 || count > 16 || count == 14) // Invalid lengths
    {
        printf("INVALID\n");
    }

    int digits[count]; // Array that will hold single-digit values of the card's number

    for (int j = 0; j < count; j++) // Put digits of card's number inside array
    {
        digits[j] = card % 10;
        card /= 10;
    }

    for (int i = 1; i < count; i += 2) // Count every other digit and multiply by 2
    {

        if ((2 * digits[i]) > 9)
        {
            checksum += (((2 * digits[i]) % 10) + 1);
        }

        else
        {
            checksum += (2 * digits[i]);
        }
    }

    for (int z = 0; z < count; z += 2) // Count the remain digits
    {
        checksum += digits[z];
    }


    if (count == 15) // AMEX
    {

        if ((digits[14] == 3 && (digits[13] == 4 || digits[13] == 7)))
        {

            if (checksum % 10 == 0)
            {
                printf("AMEX\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }

    if (count == 16) // MASTER or VISA
    {

        if (checksum % 10 == 0)
        {

            if (digits[15] == 5 && (digits[14] == 1 || digits[14] == 2 || digits[14] == 3 || digits[14] == 4 || digits[14] == 5))
            {
                printf("MASTERCARD\n");
            }

            else if (digits[15] == 4)
            {
                printf("VISA\n");
            }

            else
            {
                printf("INVALID\n");
            }

        }

        else
        {
            printf("INVALID\n");
        }
    }

    if (count == 13) // VISA
    {

        if (digits[12] == 4)
        {

            if (checksum % 10 == 0)
            {
                printf("VISA\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }
}
