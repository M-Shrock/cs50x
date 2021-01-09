#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//Get total letter count from text string
int letterCount(string text);
//Get word count separated by a space from text string
int wordCount(string text);
//Get sentence count, separated by either a period(.) exclamation(1) or question mark(?) in text string
int sentenceCount(string text);
//Calculate and return Coleman-Liau index
int calculateIndex(int letters, int words, int sentences);


int main(void)
{
    string text = get_string("Text: ");

    int letters = letterCount(text);
    int words = wordCount(text);
    int sentences = sentenceCount(text);
    int index = calculateIndex(letters, words, sentences);

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
        printf("Grade %i\n", index);
    }
}

//Get total letter count from text string
int letterCount(string text)
{
    int count = 0;

    //Iterate through sting
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //If char is lowercase, convert to uppercase
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] -= 32;
        }

        //If char is valid, increament count
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            count++;
        }
    }

    return count;
}

//Get word count separated by a space from text string
int wordCount(string text)
{
    //With no space at the end of text to count last word, count starts at 1
    int count = 1;

    //Iterate through the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //If char is a space, increament count
        if (text[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

//Get sentence count, separated by either a period(.) exclamation(!) or question mark(?) in text string
int sentenceCount(string text)
{

    int count = 0;

    //Iterate through the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //If sentence delimiter detected, increment count
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

//Calculate and return Coleman-Liau index
int calculateIndex(int letters, int words, int sentences)
{
    float lettersPer = ((float) letters / words) * 100;
    float sentencesPer = ((float) sentences / words) * 100;

    return round(0.0588 * lettersPer - 0.296 * sentencesPer - 15.8);
}