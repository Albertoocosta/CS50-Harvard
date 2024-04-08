#include <cs50.h>
#include <stdio.h>

void printHashes(int nbr)
{
    for (int i = 0; i < nbr; i++)
    {
        for (int space = 1; space < nbr - i; space++)
            printf(" ");
        for (int left = 0; left <= i; left++)
            printf("#");
        printf("  ");
        for (int right = 0; right <= i; right++)
            printf("#");
        printf("\n");
    }
}

int main(void)
{
    int height;
    do
        height = get_int("Height: ");
    while (height <= 0 || height > 8);
    printHashes(height);
}
