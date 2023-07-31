#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



void detectAndWriteFileType(const char *filename, FILE *write);


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Improper Execution\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *write = fopen("img.txt", "w");

    if (write == NULL)
    {
        printf("Error opening img.txt for writing.\n");
        return 1;
    }

    // Detect file type and find binary information inside the file
    detectAndWriteFileType(filename, write);

    fclose(write);

    return 0;
}



void detectAndWriteFileType(const char *filename, FILE *write)
{
    // Declaring new variable for storing in bytes
    typedef uint8_t BYTE;

    // Reading in binary
    FILE *file = fopen(filename, "rb");


    // Error message for file not found
    if (file == NULL)
    {
        printf("File not found: %s\n", filename);
        return;
    }


    BYTE buffer[512];

    // Reading 512 bytes at a time
    while (fread(buffer, sizeof(BYTE)*512,1 , file) == 1)
    {
        // Detect JPG header
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        {
            fprintf(write, "This is a jpg\n");
        }

        // Detect PDF header
        else if (buffer[0] == '%' && buffer[1] == 'P' && buffer[2] == 'D' && buffer[3] == 'F')
        {
            fprintf(write, "This is a pdf\n");
        }

        // Write binary information byte by byte
        for (int i = 0; i < 512; i++)
        {
            fprintf(write, "%02x ", buffer[i]);
        }
    }

    // Close file to erase dynamic memory
    fclose(file);
}