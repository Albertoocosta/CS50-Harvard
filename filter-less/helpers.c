#include "helpers.h"
#include <math.h>

#define FLOAT_TO_INT(x) ((x) >= 0.0f ? (int) ((x) + 0.5f) : (int) ((x) -0.5f))

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j].rgbtBlue + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen;
            image[i][j].rgbtRed = image[i][j].rgbtGreen;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            float sepiaRed = (0.393 * red) + (0.769 * green) + (0.189 * blue);
            float sepiaGreen = (0.349 * red) + (0.686 * green) + (0.168 * blue);
            float sepiaBlue = (0.272 * red) + (0.534 * green) + (0.131 * blue);
            if (sepiaRed > 255.0)
                sepiaRed = 255.0;
            if (sepiaGreen > 255.0)
                sepiaGreen = 255.0;
            if (sepiaBlue > 255.0)
                sepiaBlue = 255.0;
            image[i][j].rgbtRed = FLOAT_TO_INT(sepiaRed);
            image[i][j].rgbtGreen = FLOAT_TO_INT(sepiaGreen);
            image[i][j].rgbtBlue = FLOAT_TO_INT(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int large = width - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int swapRed = image[i][j].rgbtRed;
            int swapGreen = image[i][j].rgbtGreen;
            int swapBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][large - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][large - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][large - j].rgbtBlue;
            image[i][large - j].rgbtRed = swapRed;
            image[i][large - j].rgbtGreen = swapGreen;
            image[i][large - j].rgbtBlue = swapBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j] = image[i][j];
        }
     }
     for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int blue  = 0;
            int red   = 0;
            int green = 0;
            float counter = 0;
            for (int k = i - 1; k < i + 2; k++) {
                if (k < 0 || k >= height)
                    continue;
                for (int l = j - 1; l < j + 2; l++) {
                    if (l < 0 || l >= width)
                        continue;
                    red   += copy[k][l].rgbtRed;
                    green += copy[k][l].rgbtGreen;
                    blue  += copy[k][l].rgbtBlue;
                    counter++;
                }
            }
            image[i][j].rgbtRed   = round(red   / counter);
            image[i][j].rgbtGreen = round(green / counter);
            image[i][j].rgbtBlue  = round(blue  / counter);
        }
    }
}
