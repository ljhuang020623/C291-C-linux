#include <stdio.h>
#include <stdlib.h> 

int findDuplicate(int* arr, int size) {
    int result = 0;
    
    for (int i = 0; i < size; i++) {
        result ^= i;
    }

    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }

    return result;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int)); 

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int duplicate = findDuplicate(arr, size);

    printf("The duplicate number is: %d\n", duplicate);

    free(arr); 

    return 0;
}

