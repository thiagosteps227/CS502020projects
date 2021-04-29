#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)//last row has to be height-1
    {
        for (int z = 0; z < width; z++)//last pixel has to be width-1
        {
            int avg = (round(((float)image[i][z].rgbtRed + (float)image[i][z].rgbtGreen + (float)image[i][z].rgbtBlue)/3));
            avg %= 255;

            if (avg % 255 == 0)
                {}
            else
            {
               image[i][z].rgbtRed = avg;
               image[i][z].rgbtGreen = avg;
               image[i][z].rgbtBlue = avg;
            }

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int z = 0; z < width; z++)
        {
            int newred;
            int newblue;
            int newgreen;

            newred = round((float)(.393 * image[i][z].rgbtRed + .769 * image[i][z].rgbtGreen + .189 * image[i][z].rgbtBlue));
            newgreen = round((float)(.349 * image[i][z].rgbtRed + .686 * image[i][z].rgbtGreen + .168 * image[i][z].rgbtBlue));
            newblue = round((float)(.272 * image[i][z].rgbtRed + .534 * image[i][z].rgbtGreen + .131 * image[i][z].rgbtBlue));

            //if/else applying caps to values
            if (newred > 255)
                image[i][z].rgbtRed = 255;
            else
                image[i][z].rgbtRed = newred;

            //---------------------------------------------------------------------

            if (newblue > 255)
                image[i][z].rgbtBlue = 255;
            else
                image[i][z].rgbtBlue = newblue;

            //---------------------------------------------------------------------

            if (newgreen > 255)
                image[i][z].rgbtGreen = 255;
            else
                image[i][z].rgbtGreen = newgreen;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //check if height is odd or even number
    if (height % 2 == 0 || width % 2 == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int x = 0; x < width/2; x++)
            {
                int widback = (width-x) - 1;
                int switchgreen = image[i][x].rgbtGreen;
                int switchblue = image[i][x].rgbtBlue;
                int switchred = image[i][x].rgbtRed;

                image[i][x].rgbtGreen = image[i][widback].rgbtGreen;
                image[i][x].rgbtBlue = image[i][widback].rgbtBlue;
                image[i][x].rgbtRed = image[i][widback].rgbtRed;

                image[i][widback].rgbtGreen = switchgreen;
                image[i][widback].rgbtBlue = switchblue;
                image[i][widback].rgbtRed = switchred;
            }
        }
    }
    else
        for (int i = 0; i < height; i++)
            {
                for (int x = 0; x < (width/2)+1; x++)
                {
                    int widback = (width-x) - 1;

                    int switchgreen = image[i][x].rgbtGreen;
                    int switchblue = image[i][x].rgbtBlue;
                    int switchred = image[i][x].rgbtRed;

                    image[i][x].rgbtGreen = image[i][widback].rgbtGreen;
                    image[i][x].rgbtBlue = image[i][widback].rgbtBlue;
                    image[i][x].rgbtRed = image[i][widback].rgbtRed;

                    image[i][widback].rgbtGreen = switchgreen;
                    image[i][widback].rgbtBlue = switchblue;
                    image[i][widback].rgbtRed = switchred;
                }
            }


    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int avgfordiv = 0;
            int neighvalgreen = 0;
            int neighvalblue = 0;
            int neighvalred = 0;

            for (int hh = -1; hh < 2; hh++)
            {
                for (int ww = -1; ww < 2; ww++)
                {
                    if ((h+hh) != height && (w+ww) != width && (h+hh) != -1 && (w+ww) != -1)
                    {
                        //sweep
                        avgfordiv++;//count up for division
                        neighvalgreen += image[h + hh][w + ww].rgbtGreen;
                        neighvalred += image[h + hh][w + ww].rgbtRed;
                        neighvalblue += image[h + hh][w + ww].rgbtBlue;
                    }
                }
            }
            //add values to pixels
             image[h][w].rgbtGreen = (int)(round((float)neighvalgreen / avgfordiv));
             image[h][w].rgbtBlue = (int)(round((float)neighvalblue / avgfordiv));
             image[h][w].rgbtRed = (int)(round((float)neighvalred / avgfordiv));
//--------------------------------------------------------------------------------------------------------------------------------
            //check cap
             if (image[h][w].rgbtGreen <= 255)
                {}
            else
                image[h][w].rgbtGreen %= 255;

            if (image[h][w].rgbtRed <= 255)
                {}
            else
                image[h][w].rgbtRed %= 255;

            if (image[h][w].rgbtBlue <= 255)
                {}
            else
                image[h][w].rgbtBlue %= 255;
//-----------------------------------------------------------------------------------------------------------------------------------
        }
    }
    return;
}