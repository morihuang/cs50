#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tmp =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = tmp;
            image[i][j].rgbtGreen = tmp;
            image[i][j].rgbtBlue = tmp;
            //return;
        }
    }

}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed =
                round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen =
                round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue =
                round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            //return;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int tmpRed = image[i][j].rgbtRed;
            int tmpGreen = image[i][j].rgbtGreen;
            int tmpBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = tmpRed;
            image[i][width - j - 1].rgbtGreen = tmpGreen;
            image[i][width - j - 1].rgbtBlue = tmpBlue;
        }
    }

    //return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int tmpRed = 0;
    int tmpGreen = 0;
    int tmpBlue = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            /*
            int tmpRed;
            int tmpGreen;
            int tmpBlue;
            int a;
            int b;
            */

            //inner square
            if (i - 1 > 0 || j - 1 > 0 || i + 1 < height || j + 1 < width)
            {
                for (a = i - 1; a == i + 1; a++)
                {
                    for (b = j - 1; b == j + 1; b++)
                    {
                        tmpRed += copy[a][b].rgbtRed / 9.0;
                        tmpGreen += copy[a][b].rgbtGreen / 9.0;
                        tmpBlue += copy[a][b].rgbtBlue / 9.0;
                    }
                }
            }

            //left upper corner
            else if (i == 0 && j == 0)
            {
                for (a = i; a == i + 1; a++)
                {
                    for (b = j; b == j + 1; b++)
                    {
                        tmpRed += copy[a][b].rgbtRed / 4.0;
                        tmpGreen += copy[a][b].rgbtGreen / 4.0;
                        tmpBlue += copy[a][b].rgbtBlue / 4.0;
                    }
                }
            }

            //right upper corner
            else if (i == 0 && j == width - 1)
            {
                for (a = i; a == i + 1; a++)
                {
                    for (b = j; b == width - 2; b--)
                    {
                        tmpRed += copy[a][b].rgbtRed / 4.0;
                        tmpGreen += copy[a][b].rgbtGreen / 4.0;
                        tmpBlue += copy[a][b].rgbtBlue / 4.0;
                    }
                }
            }

            //left lower corner
            else if (i == height - 1 && j == 0)
            {
                for (a = i; a == height - 2; a--)
                {
                    for (b = j; b == j + 1; b++)
                    {
                        tmpRed += copy[a][b].rgbtRed / 4.0;
                        tmpGreen += copy[a][b].rgbtGreen / 4.0;
                        tmpBlue += copy[a][b].rgbtBlue / 4.0;
                    }
                }
            }

            //right lower corner
            else if (i == height - 1 && j == width - 1)
            {
                for (a = i; a == height - 2; a--)
                {
                    for (b = j; b == width - 2; b--)
                    {
                        tmpRed += copy[a][b].rgbtRed / 4.0;
                        tmpGreen += copy[a][b].rgbtGreen / 4.0;
                        tmpBlue += copy[a][b].rgbtBlue / 4.0;
                    }
                }
            }

            //upper edge
            else if (i == 0 && j > 0 && j < width - 1)
            {
                for (a = i; a == 1; a++)
                {
                    for (b = j - 1; b == j + 1; b++)
                    {
                        tmpRed += copy[a][b].rgbtRed / 6.0;
                        tmpGreen += copy[a][b].rgbtGreen / 6.0;
                        tmpBlue += copy[a][b].rgbtBlue / 6.0;
                    }
                }
            }

            //lower edge
            else if (i == height - 1 && j > 0 && j < width - 1)
            {
                for (a = i; a == height - 2; a--)
                {
                    for (b = j - 1; b == j + 1; b++)
                    {
                        tmpRed += copy[a][b].rgbtRed / 6.0;
                        tmpGreen += copy[a][b].rgbtGreen / 6.0;
                        tmpBlue += copy[a][b].rgbtBlue / 6.0;
                    }
                }
            }

            //left edge
            else if (j == 0 && i > 0 && i < height - 1)
            {
                for (b = j; b == 1; b++)
                {
                    for (a = i - 1; a == i + 1; a++)
                    {
                        tmpRed += copy[a][b].rgbtRed / 6.0;
                        tmpGreen += copy[a][b].rgbtGreen / 6.0;
                        tmpBlue += copy[a][b].rgbtBlue / 6.0;
                    }
                }
            }

            //right edge
            else if (j == width - 1 && i > 0 && i < height - 1)
            {
                for (b = j; b == width - 2; b--)
                {
                    for (a = i - 1; a == i + 1; a++)
                    {
                        tmpRed += copy[a][b].rgbtRed / 6.0;
                        tmpGreen += copy[a][b].rgbtGreen / 6.0;
                        tmpBlue += copy[a][b].rgbtBlue / 6.0;
                    }
                }
            }

            image[i][j].rgbtRed = tmpRed;
            image[i][j].rgbtGreen = tmpGreen;
            image[i][j].rgbtBlue = tmpBlue;
        }
    }

}
