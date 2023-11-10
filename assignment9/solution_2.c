#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ROWS 3
#define MAX_COLS 3

typedef struct VendingItem {
    char name[50];
    char label[3];
    double price;
    int quantity;
} VendingItem;

VendingItem vendingMachine[MAX_ROWS][MAX_COLS];

double customerBalance = 0.0;

void initializeVendingMachine() {
    int itemNumber = 1;
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            VendingItem item;
            sprintf(item.name, "Item %d", itemNumber);
            sprintf(item.label, "%c%d", 'A' + row, col + 1);
            item.price = 1.0 + itemNumber * 0.5; 
            item.quantity = 10; 
            vendingMachine[row][col] = item;
            itemNumber++;
        }
    }
}

void displayMenu() {
    printf("---------------------------------------\n");
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            printf("| %-14s", vendingMachine[row][col].name);
        }
        printf("|\n");
        for (int col = 0; col < MAX_COLS; col++) {
            printf("| %-3s", vendingMachine[row][col].label);
        }
        printf("|\n");
        printf("---------------------------------------\n");
    }
    printf("[1] Insert money\n");
    printf("[2] Check balance\n");
    printf("[3] Check price\n");
    printf("[4] Purchase\n");
    printf("[5] Return change\n");
    printf("[6] Owner menu\n");
    printf("[7] Exit\n");
    printf("Please select an option: ");
}

void insertMoney(double* balance) {
    double amount;
    printf("Amount: ");
    scanf("%lf", &amount);
    *balance += amount;
    printf("You have inserted $%.2lf\n", amount);
}

void checkBalance(double balance) {
    printf("Current balance: $%.2lf\n", balance);
}

void checkPrice() {
    char label[3];
    printf("Label: ");
    scanf("%s", label);

    int row = label[0] - 'A';
    int col = label[1] - '1';

    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        double price = vendingMachine[row][col].price;
        printf("%s is $%.2lf\n", vendingMachine[row][col].name, price);
    } else {
        printf("Invalid label. Item not found.\n");
    }
}

void purchaseItem(double* balance) {
    char label[3];
    printf("Label: ");
    scanf("%s", label);

    int row = label[0] - 'A';
    int col = label[1] - '1';

    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        VendingItem* item = &vendingMachine[row][col];
        if (item->quantity > 0 && *balance >= item->price) {
            *balance -= item->price;
            item->quantity--;
            printf("You purchased a %s for $%.2lf\n", item->name, item->price);
        } else if (item->quantity == 0) {
            printf("Sorry, %s is out of stock.\n", item->name);
        } else {
            printf("You don't have enough money to purchase %s.\n", item->name);
        }
    } else {
        printf("Invalid label. Item not found.\n");
    }
}

void returnChange(double* balance) {
    printf("$%.2lf is returned\n", *balance);
    *balance = 0.0;
}

int main() {
    initializeVendingMachine();
    int exitFlag = 0;

    while (!exitFlag) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertMoney(&customerBalance);
                break;
            case 2:
                checkBalance(customerBalance);
                break;
            case 3:
                checkPrice();
                break;
            case 4:
                purchaseItem(&customerBalance);
                break;
            case 5:
                returnChange(&customerBalance);
                break;
            case 6:
                // Implement owner menu here
                break;
            case 7:
                exitFlag = 1;
                printf("Program exited\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

