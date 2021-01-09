#include <stdio.h>
#include <cs50.h>

//User input for pyramid height
int height(void);

//Logical operations to draw pyramid by each row, strating from the top down
void drawPyramid(int h);

int main(void)
{
    int blockHeight = height();

    drawPyramid(blockHeight);
}

//User input for pyramid height
int height(void)
{
    int height;

    //Height must be between 1 and 8 inclusive
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

//Logical operations to draw pyramid by each row, strating from the top down
void drawPyramid(int h)
{
    //Number of blocks for current row, pyramid drawn from top down
    int blocks = 1;

    while (h > 0)
    {
        //Padding spaces to the left of current pyramid row, first row should have no padding
        for (int i = 1; i < h; i++)
        {
            printf(" ");
        }

        //Draw left side of pyramid
        for (int i = blocks; i > 0; i--)
        {
            printf("#");
        }

        //Draw middle 2 spaces
        printf("  ");

        //Draw right side of the pyramid
        for (int i = blocks; i > 0; i--)
        {
            printf("#");
        }

        printf("\n");

        //Decrement h (pryamid drawn from top down)
        h--;
        //Increment blocks (each sequential row has one more block than the row above it)
        blocks++;
    }
}