#include<stdio.h>

int main(void){
	int numRows, i, j;

    // Input number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);

    // Check for valid input
    if (numRows <= 0 || numRows % 2 == 0) {
        printf("Invalid input. Please enter a positive odd number.\n");
        return 1;  // Exit with an error code
    }
    // Upper part of the diamond
    for (i = 1; i <= numRows / 2 + 1; i++) {
        for (j = 1; j <= numRows / 2 + 1 - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    // Lower part of the diamond
    for (i = numRows / 2; i >= 1; i--) {
        for (j = 1; j <= numRows / 2 + 1 - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
