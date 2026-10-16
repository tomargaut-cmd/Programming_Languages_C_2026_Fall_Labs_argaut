// week5_task1_file_io.c
// Name: Argaut  Surname: Tom  Student ID: 260ADB185
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    const char *filename = DEFAULT_FILENAME;
    char line[LINE_LEN];
    int line_count = 0;

    // BONUS: Use the filename provided on the command line.
    if (argc > 1) {
        filename = argv[1];
    }

    // 1. Open the file for writing.
    printf("Writing lines to %s...\n", filename);
    fp = fopen(filename, "w");

    // 2. Check whether the file opened successfully.
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 3. Write two lines to the file.
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");

    // 4. Close the file.
    fclose(fp);

    // 5. Open the same file for reading.
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 6. Read and print each line.
    printf("Reading contents:\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    // 7. Close the file.
    fclose(fp);

    // BONUS: Print the number of lines read.
    printf("Lines read: %d\n", line_count);

    return EXIT_SUCCESS;
}