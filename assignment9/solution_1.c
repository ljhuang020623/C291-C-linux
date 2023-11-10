#include <stdio.h>
#include <string.h> 
typedef struct Address {
    char street[100];
    char city[50];
    char state[20];
    char zip[10];
} Address;

typedef struct Product {
    char name[100];
    double price;
} Product;

typedef struct LineItem {
    Product product;
    int quantity;
} LineItem;

typedef struct Invoice {
    LineItem items[10];
    Address address;
    int itemCount;
} Invoice;

Address createAddress(char* street, char* city, char* state, char* zip) {
    Address address;
    strcpy(address.street, street);
    strcpy(address.city, city);
    strcpy(address.state, state);
    strcpy(address.zip, zip);
    return address;
}

Product createProduct(char* name, double price) {
    Product product;
    strcpy(product.name, name);
    product.price = price;
    return product;
}

LineItem createLineItem(Product product, int quantity) {
    LineItem item;
    item.product = product;
    item.quantity = quantity;
    return item;
}

Invoice createInvoice(LineItem* items, Address address, int itemCount) {
    Invoice invoice;
    for (int i = 0; i < itemCount; i++) {
        invoice.items[i] = items[i];
    }
    invoice.address = address;
    invoice.itemCount = itemCount;
    return invoice;
}

void printInvoice(Invoice invoice) {
    printf("Invoice:\n");
    printf("Delivery Address:\n");
    printf("Street: %s\n", invoice.address.street);
    printf("City: %s\n", invoice.address.city);
    printf("State: %s\n", invoice.address.state);
    printf("Zip: %s\n", invoice.address.zip);
    printf("Line Items:\n");
    for (int i = 0; i < invoice.itemCount; i++) {
        printf("Product: %s\n", invoice.items[i].product.name);
        printf("Quantity: %d\n", invoice.items[i].quantity);
        printf("Price per unit: %.2f\n", invoice.items[i].product.price);
    }
}

int main() {
    Product product1 = createProduct("Product 1", 10.0);
    Product product2 = createProduct("Product 2", 20.0);
    LineItem items[] = {createLineItem(product1, 2), createLineItem(product2, 1)};
    Address address = createAddress("123 Main St", "City", "State", "12345");
    Invoice invoice = createInvoice(items, address, 2);

    printInvoice(invoice);

    return 0;
}

