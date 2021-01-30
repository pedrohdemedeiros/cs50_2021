#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float compute_letters(string text);
float compute_words(string text);
float compute_sentences(string text);
int len;

int main(void)
{
    //Get the text from user
    string text = get_string("Text: ");
    len = strlen(text);

    //Compute all parameters
    float W = compute_words(text);
    float L = compute_letters(text);
    float S = compute_sentences(text);

    //Compute final index
    float index = 0.0588 * (L * 100 / W) - 0.296 * (S * 100 / W) - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        index = round(index);
        printf("Grade %i\n", (int)index);
    }
}

//Compute number of letters
float compute_letters(string text)
{
    int letter = 0;
    for (int i = 0 ; i <= len; i++)
    {
        if (isalpha(text[i]))
        {
            letter++;
        }
    }
    return letter;
}
//Compute number of sentences
float compute_sentences(string text)
{
    int sentence = 0;
    for (int j = 0; j <= len; j++)
    {
        if ((text[j] == '.') || (text[j] == '!') || (text[j] == '?'))
        {
            sentence++;
        }
    }
    return sentence;
}
//Compute number of words
float compute_words(string text)
{
    int words = 1;
    for (int k = 0; k <= len; k++)
    {
        if (text[k] == ' ')
        {
            words++;
        }
    }
    return words;
}



