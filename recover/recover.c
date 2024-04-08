#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZEJPG 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("File was not found\n");
        return 1;
    }
    uint8_t buffer[SIZEJPG];
    FILE *actualFile = NULL;
    int count = 0;
    char *filename = malloc(8 * sizeof(char));
    if (filename == NULL)
    {
        fclose(card);
        printf("'Malloc' error\n");
        return 1;
    }
    while (fread(buffer, sizeof(uint8_t), SIZEJPG, card) == 512)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            if (actualFile != NULL)
            {
                fclose(actualFile);
            }
            sprintf(filename, "%03i.jpg", count);
            actualFile = fopen(filename, "w");
            if (actualFile == NULL)
            {
                free(filename);
                fclose(card);
                printf("Error creating file\n");
                return 1;
            }
            count++;
        }
        if (actualFile != NULL)
            fwrite(buffer, sizeof(uint8_t), SIZEJPG, actualFile);
    }
    if (actualFile != NULL)
        fclose(actualFile);
    fclose(card);
    free(filename);
    return 0;
}
