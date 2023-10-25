#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct Dish {
    char id[6];
    char name[50];
    double price;
    int stock;
    struct Dish* next;
} Dish;

typedef struct Customer {
    char name[50];
    struct Customer* next;
    struct Order* orders;
} Customer;

typedef struct Order {
    char dishName[50];
    int quantity;
    double dishPrice;
    struct Order* next;
} Order;

int generateRandomNumber() {
    return rand() % 10;
}

Dish* loadDishesFromFile() {
    char *filename = "dish.txt";
    FILE *fp = fopen(filename, "r");
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 0;
    } else {
        while (fgets(buffer, MAX_LENGTH, fp)) {
            
            sscanf(buffer, "%[^#]#%d#%d", );
        }
    }
    fclose(fp);
    return NULL;
}

void saveDishesToFile(Dish* head) {

}

Customer* loadCustomersFromFile() {
    return NULL;
}

void saveCustomersToFile(Customer* head) {
}

void insertNewDish(Dish** head) {
}

void updateDish(Dish* head) {
}

void deleteDish(Dish** head) {
}

void addCustomer(Customer** head) {
}

void viewCustomers(Customer* head) {
}

void placeOrder(Dish* dishHead, Customer* customerHead) {
}

void processPayment(Dish* dishHead, Customer** customerHead) {
}

int main() {
    srand(time(0));

    Dish* dishHead = loadDishesFromFile();
    Customer* customerHead = loadCustomersFromFile();

    int choice;

    do {
        printf("Main Menu\n");
        printf("1. Insert New Dish\n");
        printf("2. Update Dish\n");
        printf("3. Delete Dish\n");
        printf("4. Add Customer\n");
        printf("5. View Customers\n");
        printf("6. Place Order\n");
        printf("7. Process Payment\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNewDish(&dishHead);
                break;
            case 2:
                updateDish(dishHead);
                break;
            case 3:
                deleteDish(&dishHead);
                break;
            case 4:
                addCustomer(&customerHead);
                break;
            case 5:
                viewCustomers(customerHead);
                break;
            case 6:
                placeOrder(dishHead, customerHead);
                break;
            case 7:
                processPayment(dishHead, &customerHead);
                break;
            case 8:
                saveDishesToFile(dishHead);
                saveCustomersToFile(customerHead);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}