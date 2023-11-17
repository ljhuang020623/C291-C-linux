#include <stdio.h>
#include <stdlib.h>

void removeEmptyLines(FILE* inputFile) {
    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        exit(1);
    }

    char line[1000];

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        if (line[0] != '\n') {
            fputs(line, tempFile);
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    remove("input.txt");
    rename("temp.txt", "input.txt");
}

void mergeFiles(FILE* inputFile1, FILE* inputFile2, FILE* outputFile) {
    char line[1000];

    while (fgets(line, sizeof(line), inputFile1) != NULL) {
        fputs(line, outputFile);
    }

    while (fgets(line, sizeof(line), inputFile2) != NULL) {
        fputs(line, outputFile);
    }

    fclose(inputFile1);
    fclose(inputFile2);
    fclose(outputFile);
}

int main() {
    FILE* inputFile1 = fopen("input21.txt", "r");
    FILE* inputFile2 = fopen("input22.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile1 == NULL || inputFile2 == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    removeEmptyLines(inputFile1);
    removeEmptyLines(inputFile2);

    mergeFiles(inputFile1, inputFile2, outputFile);

    printf("Contents of input21.txt after removing empty lines:\n");
    rewind(inputFile1);
    char ch;
    while ((ch = fgetc(inputFile1)) != EOF) {
        putchar(ch);
    }

    printf("\nContents of input22.txt after removing empty lines:\n");
    rewind(inputFile2);
    while ((ch = fgetc(inputFile2)) != EOF) {
        putchar(ch);
    }

    printf("\nAfter merging input21.txt with input22.txt:\n");
    rewind(outputFile);
    while ((ch = fgetc(outputFile)) != EOF) {
        putchar(ch);
    }

    fclose(outputFile);
    remove("input21.txt");
    remove("input22.txt");

    return 0;
}

