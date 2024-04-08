#include <cs50.h>
#include <stdio.h>

long countDigits(long nbr)
{
    int i = 0;
    while (nbr != 0)
    {
        nbr /= 10;
        i++;
    }
    return (i);
}

long checkBank(long nbr)
{
    while (nbr > 99)
    {
        nbr = nbr / 10;
    }
    return (nbr);
}

void checkNumber(long nbr)
{
    int i = 1;
    int soma = 0;
    long check = nbr;
    int digit = 0;
    while (check != 0)
    {
        digit = check % 10;
        if (i % 2 == 0)
        {
            digit *= 2;
            soma += (digit / 10) + (digit % 10);
        }
        else
            soma += digit;
        check /= 10;
        i++;
    }
    if (soma % 10 == 0)
    {
        if ((checkBank(nbr) == 34 || checkBank(nbr) == 37) && (countDigits(nbr) == 15))
            printf("AMEX\n");
        else if ((checkBank(nbr) == 51 || checkBank(nbr) == 52 || checkBank(nbr) == 53 || checkBank(nbr) == 54 ||
                  checkBank(nbr) == 55) &&
                 (countDigits(nbr) == 16))
            printf("MASTERCARD\n");
        else if ((checkBank(nbr) / 10) == 4 && (countDigits(nbr) == 13 || countDigits(nbr) == 16))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}

int main(void)
{
    long nbr = get_long("Number: ");
    checkNumber(nbr);
}
