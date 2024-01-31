#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILENAME "file.csv"

typedef struct Lokasi {
    char location[100];
    char city[100];
    int price;
    int rooms;
    int bathroom;
    int carPark;
    char type[50];
    char furnish[50];
} Lokasi;

Lokasi houses[5000];
int houseLength;

static int sortLocationAsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    return strcmp(p1->location, p2->location);
} 

static int sortLocationDsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    return strcmp(p1->location, p2->location) * -1;
} 

static int sortCityAsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    return strcmp(p1->city, p2->city);
} 

static int sortCityDsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    return strcmp(p1->city, p2->city) * -1;
} 

static int sortPriceAsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    if (p1->price > p2->price) {
        return 1;
    } else if (p1->price < p2->price) {
        return -1;
    } else {
        return 0;
    }
} 

static int sortPriceDsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    if (p1->price > p2->price) {
        return -1;
    } else if (p1->price < p2->price) {
        return 1;
    } else {
        return 0;
    }
} 

static int sortRoomsAsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    if (p1->rooms > p2->rooms) {
        return 1;
    } else if (p1->rooms < p2->rooms) {
        return -1;
    } else {
        return 0;
    }
} 

static int sortRoomsDsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    if (p1->rooms > p2->rooms) {
        return -1;
    } else if (p1->rooms < p2->rooms) {
        return 1;
    } else {
        return 0;
    }
} 

static int sortBathroomAsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    if (p1->bathroom > p2->bathroom) {
        return 1;
    } else if (p1->bathroom < p2->bathroom) {
        return -1;
    } else {
        return 0;
    }
} 

static int sortBathroomDsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    if (p1->bathroom > p2->bathroom) {
        return -1;
    } else if (p1->bathroom < p2->bathroom) {
        return 1;
    } else {
        return 0;
    }
} 

static int sortCarparkAsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    if (p1->carPark > p2->carPark) {
        return 1;
    } else if (p1->carPark < p2->carPark) {
        return -1;
    } else {
        return 0;
    }
} 

static int sortCarparkDsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    if (p1->carPark > p2->carPark) {
        return -1;
    } else if (p1->carPark < p2->carPark) {
        return 1;
    } else {
        return 0;
    }
} 

static int sortTypeAsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    return strcmp(p1->type, p2->type);
} 

static int sortTypeDsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    return strcmp(p1->type, p2->type) * -1;
} 

static int sortFurnishAsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    return strcmp(p1->furnish, p2->furnish);
} 

static int sortFurnishDsc(const void* a, const void* b) 
{
    const Lokasi *p1 = (Lokasi *)a;
    const Lokasi *p2 = (Lokasi *)b;
    return strcmp(p1->furnish, p2->furnish) * -1;
} 

void bacaFile() {
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error: Tidak dapat membuka file %s.\n", FILENAME);
        return;
    }

    char line[1024];
    int lineNumber = -1;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (lineNumber == -1) {
            lineNumber++;
            continue;
        }
        Lokasi h;
        sscanf(line, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", h.location, h.city, &h.price, &h.rooms, &h.bathroom, &h.carPark, h.type, h.furnish);
        houses[lineNumber] = h;
        lineNumber++;
    }
    houseLength = lineNumber;

    fclose(file);
}

void buatFileBaru(char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: %s.\n", filename);
        return;
    }
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0;i < houseLength;i++) {
        Lokasi h = houses[i];
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n", h.location, h.city, h.price, h.rooms, h.bathroom, h.carPark, h.type, h.furnish);
    }
    fclose(file);
    printf("Data succesfully written to file %s", filename);
    getchar();
}

void tampilBaris(Lokasi h) {
    printf("%-20s %-20s %-20d %-20d %-20d %-20d %-20s %-20s\n",  h.location, h.city, h.price, h.rooms, h.bathroom, h.carPark, h.type, h.furnish);
}

void tampilSemua(int n) {
    printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0;i < n;i++) {
        Lokasi h = houses[i];
        printf("%-20s %-20s %-20d %-20d %-20d %-20d %-20s %-20s\n",  h.location, h.city, h.price, h.rooms, h.bathroom, h.carPark, h.type, h.furnish);
    } 
    printf("Press any key to continue....");
    getchar();
}

void tampilkanSort() {
    char column[20];
    char query[100]; 
    int data = 0;
    printf("Choose column: ");
    scanf("%s", column);
    getchar();
    printf("Sort ascending or descending? ");
    scanf("%s", query);
    getchar();

    if (strcmp(query, "dsc") == 0) {
        if (strcmp(column, "Location") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortLocationAsc);
        } else if (strcmp(column, "City") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortCityAsc);
        } else if (strcmp(column, "Price") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortPriceAsc);
        } else if (strcmp(column, "Rooms") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortRoomsAsc);
        } else if (strcmp(column, "Bathroom") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortBathroomAsc);
        } else if (strcmp(column, "Carpark") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortCarparkAsc);
        } else if (strcmp(column, "Type") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortTypeAsc);
        } else if (strcmp(column, "Furnish") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortFurnishAsc);
        } else {
            printf("404");
            getchar();
            return;
        }
        tampilSemua(10);
    } else if (strcmp(query, "asc") == 0) {
        if (strcmp(column, "Location") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortLocationDsc);
        } else if (strcmp(column, "City") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortCityDsc);
        } else if (strcmp(column, "Price") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortPriceDsc);
        } else if (strcmp(column, "Rooms") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortRoomsDsc);
        } else if (strcmp(column, "Bathroom") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortBathroomDsc);
        } else if (strcmp(column, "Carpark") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortCarparkDsc);
        } else if (strcmp(column, "Type") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortTypeDsc);
        } else if (strcmp(column, "Furnish") == 0) {
            qsort(houses, houseLength, sizeof(const Lokasi), sortFurnishDsc);
        } else {
            printf("404");
            getchar();
            return;
        }
        tampilSemua(10);
    } else {
        printf("404");
        getchar();
    }
}

void pilihRow() {
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
                tampilBaris(houses[i]);
                data++;
            }
        } else if (strcmp(column, "City") == 0) {
            if (strcmp(query, houses[i].city) == 0) {
                tampilBaris(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Price") == 0) {
            if (atoi(query) == houses[i].price) {
                tampilBaris(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Rooms") == 0) {
            if (atoi(query) == houses[i].rooms) {
                tampilBaris(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Bathroom") == 0) {
            if (atoi(query) == houses[i].bathroom) {
                tampilBaris(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Carpark") == 0) {
            if (atoi(query) == houses[i].carPark) {
                tampilBaris(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Type") == 0) {
            if (strcmp(query, houses[i].type) == 0) {
                tampilBaris(houses[i]);
                data++;
            }
        } else if (strcmp(column, "Furnish") == 0) {
            if (strcmp(query, houses[i].furnish) == 0) {
                tampilBaris(houses[i]);
                data++;
            }
        } else {
            printf("404");
            break;
        }
    }
    if (data == 0) {
        puts("Not Found");
    }
    getchar();
}

int tampilkanMenu() {
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
    bacaFile();
    while(1) {
        int choice = tampilkanMenu();
        switch(choice) {
            case 1: {
                int n;
                printf("Number of rows: ");
                scanf("%d", &n);
                getchar();
                tampilSemua(n);
                continue;
            }
            case 2: {
                pilihRow();
                continue;
            }
            case 3: {
                tampilkanSort();
                continue;
            }
            case 4: {
                char s[100];
                char res[100];
                printf("File Name: ");
                scanf("%s", s);
                sprintf(res, "%s.csv", s);
                getchar();

                buatFileBaru(res);
                continue;
            }
            case 5: {
                break;
            }
        }
        break;
    }
}