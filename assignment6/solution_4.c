#include <stdio.h>

void findMinMax(int *inputArray, int lenArray, int *min, int *max) {
    *min = *max = inputArray[0];
    for (int i = 1; i < lenArray; i++) {
        if (*(inputArray + i) > *max) {
            *max = *(inputArray + i);
        } else if (*(inputArray + i) < *min) {
            *min = *(inputArray + i);
        }
    }
}

int main() {
    int min, max;
    int inputArray[] = {15, 56, 34, 78, 23};
    int len = sizeof(inputArray) / sizeof(inputArray[0]);

    findMinMax(inputArray, len, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}

