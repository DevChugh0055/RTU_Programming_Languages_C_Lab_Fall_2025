#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

    // 1. Open file for writing (mode = "w")
    fp = fopen(filename, "w");
    
    // 2. Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    printf("Writing to %s...\n", filename);
    
    // 3. Write 2–3 lines of text to the file using fprintf()
    fprintf(fp, "Hello, File I/O in C!\n");
    fprintf(fp, "This is line 2.\n");
    fprintf(fp, "This is line 3.\n");
    
    // 4. Close the file
    fclose(fp);
    printf("Write completed.\n\n");

    // 5. Open file again for reading (mode = "r")
    fp = fopen(filename, "r");
    
    // Check if file opened successfully for reading
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    printf("Reading content from %s:\n", filename);
    
    // 6. Use fgets() in a loop to read and print each line to the console
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    
    // 7. Close the file
    fclose(fp);

    return 0;
}

    // BONUS: ask user for filename instead of using default "data.txt"
    // BONUS: count number of lines read
