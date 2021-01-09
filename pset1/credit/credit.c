#include <stdio.h>
#include <cs50.h>

//Return length of long
int long_length(long num);

//Check validity of CC num using Luhn's Algorithm, returns true if valid, false if not
bool validityCheck(long ccNum);

//Returns leading two digits of a long
long startingDigits(long ccNum);

int main(void)
{
    long cc = get_long("Number: ");

    if (validityCheck(cc))
    {
        //Switch to determin type of card
        switch (startingDigits(cc))
        {
            case 55:
            case 54:
            case 53:
            case 52:
            case 51:
                printf("MASTERCARD\n");
                break;
            case 49:
            case 48:
            case 47:
            case 46:
            case 45:
            case 44:
            case 43:
            case 42:
            case 41:
            case 40:
                printf("VISA\n");
                break;
            case 37:
                printf("AMEX\n");
                break;
            case 34:
                printf("AMEX\n");
                break;
            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

//Return length of long
int long_length(long num)
{
    int length = 0;

    while (num > 0)
    {
        ++length;
        num = num / 10;
    }

    return length;
}

//Check validity of CC num using Luhn's Algorithm, returns true if valid, false if not
bool validityCheck(long ccNum)
{
    //First check length, valid cards are 13, 15, or 16 digits long per assignment
    if (long_length(ccNum) != 13 && long_length(ccNum) != 15 && long_length(ccNum) != 16)
    {
        return false;
    }

    // Sum of every other digit, starting second to last, multiplied by 2
    long part1 = 0;

    //Sum of every other digit, starting with last
    long part2 = 0;

    //Flag to alternate digits
    bool digitFlag = true;

    while (ccNum > 0)
    {
        //flag starts true for last digit then alternates
        if (digitFlag == true)
        {
            part2 += ccNum % 10;
        }
        else
        {
            //If digit * 2 is greater than 1 digit, add digits individually to part 1 total
            int num = (ccNum % 10) * 2;
            if (num > 9)
            {
                while (num > 0)
                {
                    part1 += num % 10;
                    num = num / 10;
                }
            }
            else
            {
                part1 += num;
            }
        }

        digitFlag = !digitFlag;
        ccNum = ccNum / 10;
    }

    //printf("part1: %li part2: %li\n", part1, part2); (REMOVE)

    //If sum of both parts ends in 0 CC is valid, if not CC is invalid
    return (part1 + part2) % 10 == 0 ? true : false;
}

//Returns leading two digits of a long
long startingDigits(long ccNum)
{
    long digits = ccNum;
    while (digits > 99)
    {
        digits = digits / 10;
    }

    return digits;
}