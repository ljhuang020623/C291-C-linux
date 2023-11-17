#include <stdio.h>

void countAndOrXorPairs(int arr[], int n) {
    int andPairs = 0, orPairs = 0, xorPairs = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int andResult = arr[i] & arr[j];
            int orResult = arr[i] | arr[j];
            int xorResult = arr[i] ^ arr[j];

            if (andResult & 1) {
                andPairs++;
                printf("AND Pair: (%d, %d)\n", arr[i], arr[j]);
            }

            if (orResult & 1) {
                orPairs++;
                printf("OR Pair: (%d, %d)\n", arr[i], arr[j]);
            }

            if (xorResult & 1) {
                xorPairs++;
                printf("XOR Pair: (%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    printf("Total AND pairs: %d\n", andPairs);
    printf("Total OR pairs: %d\n", orPairs);
    printf("Total XOR pairs: %d\n", xorPairs);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countAndOrXorPairs(arr, n);

    return 0;
}

