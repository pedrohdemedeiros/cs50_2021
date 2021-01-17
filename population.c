#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int pop;
    int fpop;
    int ys = 0;

    do
    {
        pop = get_int("Initial Popularion: ");
    }
    while (pop < 9);
    // TODO: Prompt for end size

    do
    {
        fpop = get_int("Final Population: ");
    }
    while (fpop < pop);

    // TODO: Calculate number of years until we reach threshold

    while (pop < fpop)
    {
        pop = pop + pop / 3 - pop / 4;
        ys++;
    }



    // TODO: Print number of years

    printf("Years: %i", ys);
}