#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define FILENAME "file.csv"

typedef struct House {
    char location[100];
    char location2[100];
    int price;
    int rooms;
    int bathroom;
    int carPark;
    char type[50];
    char furnish[50];
} House;

House houses[10000];
int houseLength;

void readFile() {
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error: Tidak dapat membuka file %s.\n", FILENAME);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = -1;

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d\n", lineNumber);
        if (lineNumber == -1) {
            lineNumber++;
            continue;
        }
        House h;
        sscanf(line, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", h.location, h.location2, &h.price, &h.rooms, &h.bathroom, &h.carPark, h.type, h.furnish);
        houses[lineNumber] = h;
        lineNumber++;
    }
    houseLength = lineNumber;

    fclose(file);
}

void printHouseRow(House h) {
    printf("%-20s %-20s %-20d %-20d %-20d %-20d %-20s %-20s\n",  h.location, h.location2, h.price, h.rooms, h.bathroom, h.carPark, h.type, h.furnish);
}

void displayRows() {
    int n;
    printf("Number of rows: ");
    scanf("%d", &n);
    getchar();
    printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0;i < n;i++) {
        House h = houses[i];
        printf("%-20s %-20s %-20d %-20d %-20d %-20d %-20s %-20s\n",  h.location, h.location2, h.price, h.rooms, h.bathroom, h.carPark, h.type, h.furnish);
    } 
    printf("Press any key to continue....");
    getchar();
}

void displaySelectRow() {
    char column[20];
    char query[100]; 
    printf("Choose column: ");
    scanf("%s", column);
    getchar();
    printf("What data do you want to find? ");
    scanf("%s", query);
    getchar();
    printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0;i < houseLength;i++) {
        if (strcmp(column, "Location") == 0) {
            if (strcmp(query, houses[i].location) == 0) {
                printHouseRow(houses[i]);
            }
        } else if (strcmp(column, "City") == 0) {
            if (strcmp(query, houses[i].location2) == 0) {
                printHouseRow(houses[i]);
            }
        } else if (strcmp(column, "Price") == 0) {
            if (atoi(query) == houses[i].price) {
                printHouseRow(houses[i]);
            }
        } else if (strcmp(column, "Rooms") == 0) {
            if (atoi(query) == houses[i].rooms) {
                printHouseRow(houses[i]);
            }
        } else if (strcmp(column, "Bathroom") == 0) {
            if (atoi(query) == houses[i].bathroom) {
                printHouseRow(houses[i]);
            }
        } else if (strcmp(column, "Carpark") == 0) {
            if (atoi(query) == houses[i].carPark) {
                printHouseRow(houses[i]);
            }
        } else if (strcmp(column, "Type") == 0) {
            if (strcmp(query, houses[i].type) == 0) {
                printHouseRow(houses[i]);
            }
        } else if (strcmp(column, "Furnish") == 0) {
            if (strcmp(query, houses[i].furnish) == 0) {
                printHouseRow(houses[i]);
            }
        } else {
            printf("Invalid Command");
            break;
        }
    }
    getchar();
}

int displayMenu() {
    system("cls");
    int x;
    puts("What do you want to do?");
    puts("1. Display data\n2. Search Data\n3. Sort Data\n4. Export Data\n5. Exit");
    printf("Your %d choice: ", houseLength);
    scanf("%d", &x);
    return x;
}

int main() {
    readFile();
    while(1) {
        int choice = displayMenu();
        switch(choice) {
            case 1: {
                displayRows();
                continue;
            }
            case 2: {
                displaySelectRow();
                continue;
            }
        }
        break;
    }
}