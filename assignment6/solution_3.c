#include <stdio.h>

void addition(int *a, int *b) {
    *a = *a + *b;
}

void subtraction(int *a, int *b) {
    *a = *a - *b;
}

void multiplication(int *a, int *b) {
    *a = (*a) * (*b);
}

void division(int *a, int *b) {
    if (*b != 0) {
        *a = (*a) / (*b);
    } else {
        printf("Error: Division by zero!\n");
    }
}

int main() {
    char operation;
    int num1, num2;

    while (1) {
        printf("Enter the operation you want to perform ('+' for Addition, '-' for Subtraction, '*' for Multiplication, '/' for Division, Q to quit): ");
        scanf(" %c", &operation);

        if (operation == 'Q' || operation == 'q') {
            printf("Goodbye!\n");
            break;
        }

        printf("Enter the operands for this operation: ");
        scanf("%d %d", &num1, &num2);

        switch (operation) {
            case '+':
                addition(&num1, &num2);
                printf("Addition of the numbers = %d\n", num1);
                break;

            case '-':
                subtraction(&num1, &num2);
                printf("Subtraction of the numbers = %d\n", num1);
                break;

            case '*':
                multiplication(&num1, &num2);
                printf("Multiplication of the numbers = %d\n", num1);
                break;

            case '/':
                division(&num1, &num2);
                printf("Division of the numbers = %d\n", num1);
                break;

            default:
                printf("Invalid operation!\n");
        }
    }
    
    return 0;
}

