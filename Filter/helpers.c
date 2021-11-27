#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each row
    for (int i = 0; i < height; i++)
    {
        // Iterate through each pixel within the row
        for (int j = 0; j < width; j++)
        {
            // Set average to the average values of RGB
            int average = round(((float) image[i][j].rgbtRed + (float) image[i][j].rgbtBlue + (float) image[i][j].rgbtGreen) / 3);

            // Set all pixels to the calculated average
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each row
    for (int i = 0; i < height; i++)
    {
        // Iterate through each pixel within the row
        for (int j = 0; j < width; j++)
        {
            // Calculate the sepia red colour value
            int sepiaRed = round(0.393 * (float) image[i][j].rgbtRed + 0.769 * (float) image[i][j].rgbtGreen + 0.189 * (float) image[i][j].rgbtBlue);
            // Cap the calculated value at 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            // Calculate the sepia green colour value
            int sepiaGreen = round(0.349 * (float) image[i][j].rgbtRed + 0.686 * (float) image[i][j].rgbtGreen + 0.168 * (float) image[i][j].rgbtBlue);
            // Cap the calculated value at 255
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // Calculate the sepia blue colour value
            int sepiaBlue = round(0.272 * (float) image[i][j].rgbtRed + 0.534 * (float) image[i][j].rgbtGreen + 0.131 * (float) image[i][j].rgbtBlue);
            // Cap the calculated value at 255
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Change each RGB colour within the pixel to the calculated sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each row
    for (int i = 0; i < height; i++)
    {
        // Iterate through each pixel halfway within the row
        for (int j = 0; j < (width / 2); j++)
        {
            // Set a temporary variable to store current pixel
            RGBTRIPLE temp = image[i][j];

            //Swap contents of current pixel with last pixel on other end of the row
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int averageCounter = 0;
            int tempRed = 0;
            int tempGreen = 0;
            int tempBlue = 0;

            if (i > 0 && j > 0)
            {
                tempRed += image[i - 1][j - 1].rgbtRed;
                tempGreen += image[i - 1][j - 1].rgbtGreen;
                tempBlue += image[i - 1][j - 1].rgbtBlue;
                averageCounter++;
            }

            if (i > 0)
            {
                tempRed += image[i - 1][j].rgbtRed;
                tempGreen += image[i - 1][j].rgbtGreen;
                tempBlue += image[i - 1][j].rgbtBlue;
                averageCounter++;
            }

            if (i > 0 && j < width - 1)
            {
                tempRed += image[i - 1][j + 1].rgbtRed;
                tempGreen += image[i - 1][j + 1].rgbtGreen;
                tempBlue += image[i - 1][j + 1].rgbtBlue;
                averageCounter++;
            }

            if (j > 0)
            {
                tempRed += image[i][j - 1].rgbtRed;
                tempGreen += image[i][j - 1].rgbtGreen;
                tempBlue += image[i][j - 1].rgbtBlue;
                averageCounter++;
            }

            tempRed += image[i][j].rgbtRed;
            tempGreen += image[i][j].rgbtGreen;
            tempBlue += image[i][j].rgbtBlue;
            averageCounter++;

            if (j < width - 1)
            {
                tempRed += image[i][j + 1].rgbtRed;
                tempGreen += image[i][j + 1].rgbtGreen;
                tempBlue += image[i][j + 1].rgbtBlue;
                averageCounter++;
            }

            if (i < height - 1 && j > 0)
            {
                tempRed += image[i + 1][j - 1].rgbtRed;
                tempGreen += image[i + 1][j - 1].rgbtGreen;
                tempBlue += image[i + 1][j - 1].rgbtBlue;
                averageCounter++;
            }

            if (i < height - 1)
            {
                tempRed += image[i + 1][j].rgbtRed;
                tempGreen += image[i + 1][j].rgbtGreen;
                tempBlue += image[i + 1][j].rgbtBlue;
                averageCounter++;
            }

            if (i < height - 1 && j < width - 1)
            {
                tempRed += image[i + 1][j + 1].rgbtRed;
                tempGreen += image[i + 1][j + 1].rgbtGreen;
                tempBlue += image[i + 1][j + 1].rgbtBlue;
                averageCounter++;
            }

            image[i][j].rgbtRed = round((float) tempRed / averageCounter);
            image[i][j].rgbtGreen = round((float) tempGreen / averageCounter);
            image[i][j].rgbtBlue = round((float) tempBlue / averageCounter);
        }
    }
    return;
}
