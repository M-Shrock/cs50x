#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Encyrpt plaintext using key
string encyrpt(string text, string key);
//Check cipher for correct format
bool validCipher(string cipher);

//Key must be size of alphabet per assignment
const int SIZE_OF_ALPHABET = 26;

int main(int argc, string argv[])
{
    string key = argv[1];

    //Check for correct number of arguments
    if (argc == 1 || argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (validCipher(key))
    {
        printf("Key must contain 26 non-repeating alphabetic characters\n");
        return 1;
    }

    string plainText = get_string("plaintext:  ");

    printf("ciphertext: %s\n", encyrpt(plainText, key));

    return 0;
}

//Encyrpt plaintext using key
string encyrpt(string text, string key)
{
    int textLength = strlen(text);
    bool uppercase = false;

    //Convert key to all uppercase chars, key must be size of alphabet per assignment
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (islower(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }

    for (int i = 0; i < textLength; i++)
    {
        //Set flag to perserve letter case
        if (isupper(text[i]))
        {
            uppercase = true;
        }
        else
        {
            uppercase = false;
            text[i] = toupper(text[i]);
        }

        //If current char is alphabetic apply cipher
        if (isalpha(text[i]))
        {
            //All alphabetic char are uppercase, subtracting 'A' finds its index in the alphabet
            //using alphabet index, plaintext char is replaced with coorsponding char in key
            text[i] = key[text[i] - 'A'];
        }

        //Return char to its original case
        if (!uppercase)
        {
            text[i] = tolower(text[i]);
        }
    }

    return text;
}

//Check cipher for correct format
bool validCipher(string cipher)
{
    int strLength = strlen(cipher);
    char dupe[SIZE_OF_ALPHABET];

    //Check for correct command-line argument length
    if (strLength != SIZE_OF_ALPHABET)
    {
        return 1;
    }

    //Check for non-repeating alphabetic chars
    for (int i = 0; i < strLength; i++)
    {
        //Return error if any char is not alphabetic
        if (!isalpha(cipher[i]))
        {
            return 1;
        }

        //Check for duplicates, if char not duplicate added to dupe
        for (int j = 0; j < i; j++)
        {
            if (cipher[i] == dupe[j])
            {
                return 1;
            }
        }

        dupe[i] = cipher[i];
    }

    return 0;
}