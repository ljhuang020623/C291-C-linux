#include <stdio.h>

void printUniqueElements(int *inputArray, int lenArray) {
    if (lenArray == 0) return;

    int *current = inputArray;
    for (int i = 1; i < lenArray; i++) {
        if (*current != inputArray[i]) {
            printf("%d ", *current);
            current = &inputArray[i];
        }
    }
    printf("%d\n", *current);
}

int main() {
    int inputArray1[] = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    int len1 = sizeof(inputArray1) / sizeof(inputArray1[0]);
    printf("Example 1 - Unique Elements: ");
    printUniqueElements(inputArray1, len1);
    
    int inputArray2[] = {2, 2, 3, 3, 3, 4, 5, 5, 5};
    int len2 = sizeof(inputArray2) / sizeof(inputArray2[0]);
    printf("Example 2 - Unique Elements: ");
    printUniqueElements(inputArray2, len2);

    return 0;
}

