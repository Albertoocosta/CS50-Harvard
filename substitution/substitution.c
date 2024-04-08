#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check(string key)
{
    int len;

    len = strlen(key);

    if (len != 26)
        return (false);
    for (int i = 0; i < len; i++)
        key[i] = toupper(key[i]);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
            return (false);
        for (int j = i + 1; j < len; j++)
        {
            if (key[i] == key[j])
                return (false);
        }
    }
    return (true);
}

int main(int argc, string argv[])
{
    string message;
    string key = argv[1];
    int len;
    int index;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }
    if (!check(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    message = get_string("plaintext: ");
    len = strlen(message);
    char cipher[len + 1];
    for (int i = 0; i < len; i++)
    {
        if (islower(message[i]))
        {
            index = message[i] - 97;
            cipher[i] = key[index];
            if (isupper(cipher[i]))
                cipher[i] += 32;
        }
        else if (isupper(message[i]))
        {
            index = message[i] - 65;
            cipher[i] = key[index];
            if (islower(cipher[i]))
                cipher[i] += 32;
        }
        else
            cipher[i] = message[i];
    }
    cipher[len] = '\0';
    printf("ciphertext: %s\n", cipher);
}
