#include <stdio.h>

void reverseInteger(int *num) {
    int reversed = 0;
    while (*num != 0) {
        reversed = reversed * 10 + (*num % 10);
        *num /= 10;
    }
    *num = reversed;
}

int main() {
    int number;

    printf("Please enter an integer: ");
    scanf("%d", &number);

    reverseInteger(&number);
    printf("Reversed Output: %d\n", number);
    
    return 0;
}

