#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensure the usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover the infile\n");
        return 1;
    }

    // remember the filenames
    char *infile = argv[1];

    // input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int imageCount = 0;

    char filename[8];
    FILE *outptr = NULL;

    while (true)
    {
        // Reading a block of the memory card image
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        // Looping when the end of the card image is reached
        if (bytesRead == 0 && feof(inptr))
        {
            break;
        }

        // check if JPEG is found
        bool containsJpegHeader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // if another JPEG is found, close the previous file
        if (containsJpegHeader && outptr != NULL)
        {
            fclose(outptr);
            imageCount++;
        }

        // if JPEG is found, open the file for writing
        if (containsJpegHeader)
        {
            sprintf(filename, "%03i.jpg", imageCount);
            outptr = fopen(filename, "w");
        }

        // write anytime we have an open file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
        }
    }

    // closing the last jpeg
    fclose(outptr);

    // close the infile
    fclose(inptr);

    // in case of success
    return 0;
}