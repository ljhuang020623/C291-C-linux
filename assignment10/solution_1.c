#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentRecord {
    int studentID;
    char name[50];
    char courseCode[10];
};

void insertRecord(FILE* recordsFile, struct StudentRecord newRecord) {
    fwrite(&newRecord, sizeof(struct StudentRecord), 1, recordsFile);
}

void searchRecord(FILE* recordsFile, int searchID) {
    struct StudentRecord record;
    int found = 0;

    rewind(recordsFile);

    while (fread(&record, sizeof(struct StudentRecord), 1, recordsFile)) {
        if (record.studentID == searchID) {
            found = 1;
            printf("Student ID: %d\n", record.studentID);
            printf("Name: %s\n", record.name);
            printf("Course Code: %s\n", record.courseCode);
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", searchID);
    }
}

void displayAllRecords(FILE* recordsFile) {
    struct StudentRecord record;

    rewind(recordsFile);

    while (fread(&record, sizeof(struct StudentRecord), 1, recordsFile)) {
        printf("Student ID: %d\n", record.studentID);
        printf("Name: %s\n", record.name);
        printf("Course Code: %s\n", record.courseCode);
        printf("\n");
    }
}

void removeRecord(FILE* recordsFile, int removeID) {
    FILE* tempFile = fopen("tempfile.dat", "wb");
    struct StudentRecord record;

    rewind(recordsFile);

    while (fread(&record, sizeof(struct StudentRecord), 1, recordsFile)) {
        if (record.studentID != removeID) {
            fwrite(&record, sizeof(struct StudentRecord), 1, tempFile);
        }
    }

    fclose(recordsFile);
    fclose(tempFile);

    remove("studentrecords.csv");
    rename("tempfile.dat", "studentrecords.csv");

    recordsFile = fopen("studentrecords.csv", "ab+");
    printf("Records of student with ID %d removed.\n", removeID);
}

void modifyRecord(FILE* recordsFile, int modifyID, char* newCourseCode) {
    struct StudentRecord record;
    int found = 0;

    rewind(recordsFile);

    while (fread(&record, sizeof(struct StudentRecord), 1, recordsFile)) {
        if (record.studentID == modifyID) {
            found = 1;
            strcpy(record.courseCode, newCourseCode);
            fseek(recordsFile, -sizeof(struct StudentRecord), SEEK_CUR);
            fwrite(&record, sizeof(struct StudentRecord), 1, recordsFile);
            printf("Course code for student with ID %d modified.\n", modifyID);
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found. Cannot modify course code.\n", modifyID);
    }
}
int main() {
    FILE* recordsFile = fopen("studentrecords.csv", "ab+");
    FILE* commandsFile = fopen("input_p1_ex1.txt", "r");

    if (recordsFile == NULL || commandsFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    struct StudentRecord newRecord;
    int command;
    int searchID;
    int removeID;
    int modifyID;
    char newCourseCode[10];

    while (fscanf(commandsFile, "%d", &command) != EOF) {
        switch (command) {
            case 1:
                fscanf(commandsFile, "%d %s %s", &newRecord.studentID, newRecord.name, newRecord.courseCode);
                insertRecord(recordsFile, newRecord);
                printf("Record inserted.\n");
                break;
            case 2:
                fscanf(commandsFile, "%d", &searchID);
                searchRecord(recordsFile, searchID);
                break;
            case 3:
                displayAllRecords(recordsFile);
                break;
            case 4:
                fscanf(commandsFile, "%d", &removeID);
                removeRecord(recordsFile, removeID);
                break;
            case 5:
                fscanf(commandsFile, "%d %s", &modifyID, newCourseCode);
                modifyRecord(recordsFile, modifyID, newCourseCode);
                break;
            default:
                printf("Invalid command.\n");
        }
    }

    fclose(recordsFile);
    fclose(commandsFile);

    return 0;
}

