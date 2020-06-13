#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int  i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            {
               int red = (255 - image[i][j].rgbtRed);
               int green = (255 - image[i][j].rgbtGreen);
               int blue = (255 -  image[i][j].rgbtBlue);
               int t =round((red+green+blue)/3);
               if(t>85)
               {
                   image[i][j].rgbtRed =image[i][j].rgbtGreen = image[i][j].rgbtBlue =   255 - t;
               }
               else
               {
                   image[i][j].rgbtRed =image[i][j].rgbtGreen = image[i][j].rgbtBlue =  85 - t;
               }


            }
        }
    }
return;
}


void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int  i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            {
                int sepiaRed =round(.393 * image[i][j].rgbtRed  + .769 *  image[i][j].rgbtGreen+ .189 * image[i][j].rgbtBlue);
                int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
                int sepiaBlue =round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
                if(sepiaRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else if(sepiaRed < 0)
                {
                    image[i][j].rgbtRed = 0;
                }
                else
                {
                    image[i][j].rgbtRed = sepiaRed;
                }
                if(sepiaGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else if(sepiaGreen < 0)
                {
                    image[i][j].rgbtGreen = 0;
                }
                else
                {
                    image[i][j].rgbtGreen = sepiaGreen;
                }
                if(sepiaBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else if(sepiaBlue < 0)
                {
                    image[i][j].rgbtBlue = 0;
                }
                else
                {
                    image[i][j].rgbtBlue = sepiaBlue;
                }

            }
        }
    }
    return;
}


void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            image[i][j].rgbtRed = image[i][(width-1)-j].rgbtRed;
            image[i][j].rgbtGreen = image[i][(width-1)-j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][(width-1)-j].rgbtBlue;

        }
    }
    return;
}
