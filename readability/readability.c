#include <cs50.h>
#include <math.h>
#include <stdio.h>

void readability(char *str)
{
    int i = 0;
    int letter = 0;
    int word = 1;
    int sentences = 0;
    while (str[i] != 0)
    {
        if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
            letter++;
        if (str[i] == 32)
            word++;
        if (str[i] == 63 || str[i] == 46 || str[i] == 21)
            sentences++;
        i++;
    }
    float averageWords = (100 / (float) word) * (float) letter;
    float averageSentences = (100 / (float) word) * (float) sentences;
    int index = round(0.0588 * averageWords - 0.296 * averageSentences - 15.8);

    if (index < 1)
        printf("Before Grade 1\n");
    else if (index > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", index);
}

int main(void)
{
    string message = get_string("Text: ");
    readability(message);
}
