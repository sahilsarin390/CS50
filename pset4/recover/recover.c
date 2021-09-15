#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 512

int main(int argc, char *argv[])
{
    // Open file
    FILE* input = fopen("card.raw", "r");
    if (input == NULL)
    {
        printf("Could not open card.raw.\n");
        return 2;
    }

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }


    unsigned char buffer[BUFF_SIZE];

    int fcount = 0;

    FILE* picture = NULL;

    int jpeg_found = 0;

    // Looping through blocks
    while (fread(buffer, BUFF_SIZE, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpeg_found == 1)
            {
                fclose(picture);
            }
            else
            {
                jpeg_found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", fcount);
            picture = fopen(filename, "a");
            fcount++;
        }

        if (jpeg_found == 1)
        {
            fwrite(&buffer, BUFF_SIZE, 1, picture);
        }

    }

    fclose(input);
    fclose(picture);

    return 0;
}