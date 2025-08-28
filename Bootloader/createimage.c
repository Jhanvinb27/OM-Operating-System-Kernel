// createimage.c - COS 318 Project 1
// Compile with: gcc -m32 -o createimage createimage.c

#include <stdio.h>
#include <stdlib.h>

#define SECTOR_SIZE 512

void read_exec_file(const char *filename, FILE *img)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        perror("fopen");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    unsigned char *buffer = malloc(size);
    fread(buffer, 1, size, f);
    fwrite(buffer, 1, size, img);

    // Pad to sector
    if (size % SECTOR_SIZE != 0)
    {
        unsigned char pad[SECTOR_SIZE] = {0};
        fwrite(pad, 1, SECTOR_SIZE - (size % SECTOR_SIZE), img);
    }

    free(buffer);
    fclose(f);
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage: %s <imagefile> <bootblock> <kernel>\n", argv[0]);
        return 1;
    }

    FILE *img = fopen(argv[1], "wb");
    if (!img)
    {
        perror("fopen image");
        return 1;
    }

    read_exec_file(argv[2], img); // bootblock
    read_exec_file(argv[3], img); // kernel

    fclose(img);
    printf("OS image created successfully!\n");
    return 0;
}
