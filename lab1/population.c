#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize, endSize, popSize;
    // TODO: Prompt for start size
    do
    {
        startSize = get_int("Start size: ");
    } while (startSize < 9);

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("End size: ");
    } while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    popSize = startSize;
    int born, dies;
    int years = 0;

    while (popSize < endSize)
    {
        born = popSize / 3;
        dies = popSize / 4;
        popSize = popSize + born - dies;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}