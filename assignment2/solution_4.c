#include <stdio.h>

int main() {
    int year, month, day;

    printf("Enter a year: ");
    scanf("%d", &year);

    printf("Enter a month: ");
    scanf("%d", &month);

    printf("Enter a day: ");
    scanf("%d", &day);

    int isLeap = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeap = 1; 
    }
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("The date is invalid.\n");
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        printf("The date is invalid.\n");
    } else if (month == 2) {
        if (isLeap && day > 29) {
            printf("The date is invalid.\n");
        } else if (!isLeap && day > 28) {
            printf("The date is invalid.\n");
        } else {
            printf("The date is valid.\n");
        }
    } else {
        printf("The date is valid.\n");
    }

    return 0;
}

