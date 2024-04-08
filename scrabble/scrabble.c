#include <cs50.h>
#include <stdio.h>

int scrabble(char *str)
{
    int i = 0;
    int sum = 0;
    while (str[i] != 0)
    {
        if (str[i] == 'k' || str[i] == 'K')
            sum += 5;
        else if (str[i] == 'q' || str[i] == 'Q' || str[i] == 'z' || str[i] == 'Z')
            sum += 10;
        else if (str[i] == 'j' || str[i] == 'J' || str[i] == 'x' || str[i] == 'X')
            sum += 8;
        else if (str[i] == 'd' || str[i] == 'D' || str[i] == 'g' || str[i] == 'G')
            sum += 2;
        else if (str[i] == 'b' || str[i] == 'B' || str[i] == 'c' || str[i] == 'C' || str[i] == 'M' || str[i] == 'm' ||
                 str[i] == 'p' || str[i] == 'P')
            sum += 3;
        else if (str[i] == 'f' || str[i] == 'F' || str[i] == 'h' || str[i] == 'H' || str[i] == 'v' || str[i] == 'V' ||
                 str[i] == 'w' || str[i] == 'W' || str[i] == 'y' || str[i] == 'Y')
            sum += 4;
        else if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' ||
                 str[i] == 'l' || str[i] == 'L' || str[i] == 'n' || str[i] == 'N' || str[i] == 'o' || str[i] == 'O' ||
                 str[i] == 'r' || str[i] == 'R' || str[i] == 's' || str[i] == 'S' || str[i] == 't' || str[i] == 'T' ||
                 str[i] == 'u' || str[i] == 'U')
            sum += 1;
        i++;
    }
    return (sum);
}

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    if (scrabble(word1) > scrabble(word2))
        printf("Player 1 wins!\n");
    else if (scrabble(word1) < scrabble(word2))
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}
