#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Alias uint8_t as BYTE
typedef uint8_t BYTE;

// Buffer size for FAT file structure
const int BUFFER_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage ./recover card.raw\n");
        return 1;
    }

    // Open forensic image
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Initialise variables
    BYTE buffer[BUFFER_SIZE];
    int image_count = 0;
    FILE *image = NULL;
    char filename[8];

    // Repeat until end of data on card
    while (fread(&buffer, BUFFER_SIZE, 1, card) == 1)
    {
        // Check if new jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // If not the first image file close off previous image file
            if (image_count != 0)
            {
                fclose(image);
            }

            // Initialise and open new image file and increase file counter
            sprintf(filename, "%03i.jpg", image_count);
            image = fopen(filename, "w");
            image_count++;
        }

        // If jpeg image found write data into file
        if (image_count != 0)
        {
            fwrite(&buffer, BUFFER_SIZE, 1, image);
        }
    }

    // Close files
    fclose(card);
    fclose(image);

    return 0;
}