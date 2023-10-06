#include <stdio.h>

void copyArray(int *srcArray, int *destArray, int lenArray) {
    for (int i = 0; i < lenArray; i++) {
        *(destArray + i) = *(srcArray + i);
    }
}

int main() {
    int srcArray[] = {15, 56, 34, 78, 23};
    int lenArray = sizeof(srcArray) / sizeof(srcArray[0]);
    int destArray[lenArray];

    copyArray(srcArray, destArray, lenArray);

    printf("Destination Array: ");
    for (int i = 0; i < lenArray; i++) {
        printf("%d", destArray[i]);
        if (i < lenArray - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}

