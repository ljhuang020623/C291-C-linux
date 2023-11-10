#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int* data;
    size_t length;
} Array;

Array* new_array(size_t len) {
    Array* arr = (Array*)malloc(sizeof(Array));
    if (arr == NULL) {
        return NULL;
    }
    arr->data = (int*)malloc(len * sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }
    arr->length = len;

    for (size_t i = 0; i < len; i++) {
        arr->data[i] = 0;
    }

    return arr;
}

int array_get(Array* arr, int index) {
    if (index >= 0 && index < arr->length) {
        return arr->data[index];
    } else {
        return -1;
    }
}

void array_set(Array* arr, int index, int value) {
    if (index >= 0 && index < arr->length) {
        arr->data[index] = value;
    }
}

void delete_array(Array* arr) {
    if (arr != NULL) {
        free(arr->data);
        free(arr);
    }
}

int main() {
    Array* arr = new_array(5);
    array_set(arr, 0, 2);
    array_set(arr, 1, 3);
    array_set(arr, 2, 5);
    array_set(arr, 3, 7);
    array_set(arr, 4, 11);

    for (size_t i = 0; i < arr->length; i++) {
        printf("%d ", array_get(arr, i));
    }

    delete_array(arr);

    return 0;
}

