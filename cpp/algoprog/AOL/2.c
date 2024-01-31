#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define FILENAME "file.csv"

/* 

Name of Lecturer :  Pandu Wicaksono
Date			 :  26 December 2023
Class			 :  LB83
Topic			 :  Material Review II

Group Members:
1. Achmed Fidel Ghibran Bn - 2702339601

*/


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

//qsort
static int compareLocationAsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    return strcmp(p1->location, p2->location);
} 

static int compareLocationDsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    return strcmp(p1->location, p2->location) * -1;
} 

static int compareCityAsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    return strcmp(p1->location2, p2->location2);
} 

static int compareCityDsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    return strcmp(p1->location2, p2->location2) * -1;
} 

static int comparePriceAsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    if (p1->price > p2->price) {
        return 1;
    } else if (p1->price < p2->price) {
        return -1;
    } else {
        return 0;
    }
} 

static int comparePriceDsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    if (p1->price > p2->price) {
        return -1;
    } else if (p1->price < p2->price) {
        return 1;
    } else {
        return 0;
    }
} 

static int compareRoomsAsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    if (p1->rooms > p2->rooms) {
        return 1;
    } else if (p1->rooms < p2->rooms) {
        return -1;
    } else {
        return 0;
    }
} 

static int compareRoomsDsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    if (p1->rooms > p2->rooms) {
        return -1;
    } else if (p1->rooms < p2->rooms) {
        return 1;
    } else {
        return 0;
    }
} 

static int compareBathroomAsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    if (p1->bathroom > p2->bathroom) {
        return 1;
    } else if (p1->bathroom < p2->bathroom) {
        return -1;
    } else {
        return 0;
    }
} 

static int compareBathroomDsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    if (p1->bathroom > p2->bathroom) {
        return -1;
    } else if (p1->bathroom < p2->bathroom) {
        return 1;
    } else {
        return 0;
    }
} 

static int compareCarparkAsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    if (p1->carPark > p2->carPark) {
        return 1;
    } else if (p1->carPark < p2->carPark) {
        return -1;
    } else {
        return 0;
    }
} 

static int compareCarparkDsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    if (p1->carPark > p2->carPark) {
        return -1;
    } else if (p1->carPark < p2->carPark) {
        return 1;
    } else {
        return 0;
    }
} 

static int compareTypeAsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    return strcmp(p1->type, p2->type);
} 

static int compareTypeDsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    return strcmp(p1->type, p2->type) * -1;
} 

static int compareFurnishAsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    return strcmp(p1->furnish, p2->furnish);
} 

static int compareFurnishDsc(const void* a, const void* b) 
{
    const House *p1 = (House *)a;
    const House *p2 = (House *)b;
    return strcmp(p1->furnish, p2->furnish) * -1;
} 

void readFile() {
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error: Tidak dapat membuka file %s.\n", FILENAME);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = -1;

    while (fgets(line, sizeof(line), file) != NULL) {
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

void createNewFile(char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Tidak dapat membuka file %s.\n", filename);
        return;
    }
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0;i < houseLength;i++) {
        House h = houses[i];
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n", h.location, h.location2, h.price, h.rooms, h.bathroom, h.carPark, h.type, h.furnish);
    }
    fclose(file);
    printf("Data succesfully written to file %s", filename);
    getchar();
}

void printHouseRow(House h) {
    printf("%-20s %-20s %-20d %-20d %-20d %-20d %-20s %-20s\n",  h.location, h.location2, h.price, h.rooms, h.bathroom, h.carPark, h.type, h.furnish);
}

void displayRows(int n) {
    printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0;i < n;i++) {
        House h = houses[i];
        printf("%-20s %-20s %-20d %-20d %-20d %-20d %-20s %-20s\n",  h.location, h.location2, h.price, h.rooms, h.bathroom, h.carPark, h.type, h.furnish);
    } 
    printf("Press any key to continue....");
    getchar();
}

void displaySortRow() {
    char column[20];
    char query[100]; 
    int data = 0;
    printf("Choose column: ");
    scanf("%s", column);
    getchar();
    printf("Sort ascending or descending? ");
    scanf("%s", query);
    getchar();

    if (strcmp(query, "asc") == 0) {
        if (strcmp(column, "Location") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareLocationAsc);
        } else if (strcmp(column, "City") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareCityAsc);
        } else if (strcmp(column, "Price") == 0) {
            qsort(houses, houseLength, sizeof(const House), comparePriceAsc);
        } else if (strcmp(column, "Rooms") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareRoomsAsc);
        } else if (strcmp(column, "Bathroom") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareBathroomAsc);
        } else if (strcmp(column, "Carpark") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareCarparkAsc);
        } else if (strcmp(column, "Type") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareTypeAsc);
        } else if (strcmp(column, "Furnish") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareFurnishAsc);
        } else {
            printf("Invalid Command");
            getchar();
            return;
        }
        displayRows(10);
    } else if (strcmp(query, "dsc") == 0) {
        if (strcmp(column, "Location") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareLocationDsc);
        } else if (strcmp(column, "City") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareCityDsc);
        } else if (strcmp(column, "Price") == 0) {
            qsort(houses, houseLength, sizeof(const House), comparePriceDsc);
        } else if (strcmp(column, "Rooms") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareRoomsDsc);
        } else if (strcmp(column, "Bathroom") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareBathroomDsc);
        } else if (strcmp(column, "Carpark") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareCarparkDsc);
        } else if (strcmp(column, "Type") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareTypeDsc);
        } else if (strcmp(column, "Furnish") == 0) {
            qsort(houses, houseLength, sizeof(const House), compareFurnishDsc);
        } else {
            printf("Invalid Command");
            getchar();
            return;
        }
        displayRows(10);
    } else {
        printf("Invalid Command");
        getchar();
    }
}

void displaySelectRow() {
    char column[20];
    char query[100]; 
    int data = 0;
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
                data++;
            }
        } else if (strcmp(column, "City") == 0) {
            if (strcmp(query, houses[i].location2) == 0) {
                printHouseRow(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Price") == 0) {
            if (atoi(query) == houses[i].price) {
                printHouseRow(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Rooms") == 0) {
            if (atoi(query) == houses[i].rooms) {
                printHouseRow(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Bathroom") == 0) {
            if (atoi(query) == houses[i].bathroom) {
                printHouseRow(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Carpark") == 0) {
            if (atoi(query) == houses[i].carPark) {
                printHouseRow(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Type") == 0) {
            if (strcmp(query, houses[i].type) == 0) {
                printHouseRow(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Furnish") == 0) {
            if (strcmp(query, houses[i].furnish) == 0) {
                printHouseRow(houses[i]);
                data++;
            }
        } else {
            printf("Invalid Command");
            break;
        }
    }
    if (data == 0) {
        puts("Not Found");
    }
    getchar();
}

int displayMenu() {
    system("cls");
    int x;
    puts("What do you want to do?");
    puts("1. Display data\n2. Search Data\n3. Sort Data\n4. Export Data\n5. Exit");
    printf("Your choice: ");
    scanf("%d", &x);
    getchar();
    return x;
}

int main() {
    readFile();
    while(1) {
        int choice = displayMenu();
        switch(choice) {
            case 1: {
                int n;
                printf("Number of rows: ");
                scanf("%d", &n);
                getchar();
                displayRows(n);
                continue;
            }
            case 2: {
                displaySelectRow();
                continue;
            }
            case 3: {
                displaySortRow();
                continue;
            }
            case 4: {
                char s[100];
                char res[100];
                printf("File Name: ");
                scanf("%s", s);
                sprintf(res, "%s.csv", s);
                getchar();

                createNewFile(res);
                continue;
            }
            case 5: {
                break;
            }
        }
        break;
    }
}