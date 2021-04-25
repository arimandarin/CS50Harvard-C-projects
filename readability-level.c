#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // Promp user for a text
    string text1 = get_string("Text: ");

    // Counting how many letters there is on a text and passing the value to the variable letter
    int letters = count_letters(text1);

    // Counting how many words there is on a text and passing the value to the variable words
    int words = count_words(text1);

    // Counting how many sentences there is on a text and passing the value to the variable sentences
    int sentences = count_sentences(text1);

    // Coleman-Liau formula
    float L = (float) letters / (float) words * 100;

    float S = (float) sentences / (float) words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Printing the grade level
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

// Function to count letters
int count_letters(string text)
{
    int count = 0;

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if isalpha(text[i])
        {
            count++;
        }
    }
    return count;
}
// Function to count words
int count_words(string text)
{
    int count = 0;

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if isspace(text[i])
        {
            count++;
        }
    }
    return count + 1;
}

// Function to count sentenes
int count_sentences(string text)
{
    int count = 0;

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if ((text[i]) == '.' || (text[i]) == '?' || (text[i]) == '!')
        {
            count++;
        }
    }
    return count;
}
