#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2702339601 Achmed Fidel Ghibran Bn
2702241875 Nicolas Maulana SS
*/

typedef struct Book {
    char bookID[50];
    char bookTitle[255];
    char authorName[255];
    int yearPublished;
} Book;

Book bookRecords[100];
int bookCount;

static int myCompare(const void* a, const void* b) 
{
    const Book *p1 = (Book *)a;
    const Book *p2 = (Book *)b;
    return strcmp(p1->bookTitle, p2->bookTitle);
} 

void displayIndividualRecord(Book book) {
    printf("+---------------------------------------------------------------------------------+\n");
    printf("| %10s | %20s | %20s | %20s |\n", "Book ID", "Book Title", "Author Name", "Year Published");
    printf("+---------------------------------------------------------------------------------+\n");
    printf("| %10s | %20s | %20s | %20d |\n", book.bookID, book.bookTitle, book.authorName, book.yearPublished);
    printf("+---------------------------------------------------------------------------------+\n");
}

void displayAllRecords() {
    printf("+---------------------------------------------------------------------------------+\n");
    printf("| %10s | %20s | %20s | %20s |\n", "Book ID", "Book Title", "Author Name", "Year Published");
    printf("+---------------------------------------------------------------------------------+\n");
    qsort(bookRecords, bookCount, sizeof(const Book), myCompare); 
    for(int i = 0;i < bookCount;i++) {
        if(strcmp(bookRecords[i].bookID, "NULL") == 0) continue;
        printf("| %10s | %20s | %20s | %20d |\n", bookRecords[i].bookID, bookRecords[i].bookTitle, bookRecords[i].authorName, bookRecords[i].yearPublished);
    }
    printf("+---------------------------------------------------------------------------------+\n");
    getchar();
}

Book inputRecord(int needBookID) {
    Book book;
    if (needBookID == 1) {
        printf("Input Book ID: ");
        scanf("%s", book.bookID);
        getchar();
    }
    printf("Input Book Title: ");
    scanf("%s", book.bookTitle);
    getchar();
    printf("Input Author Name: ");
    scanf("%s", book.authorName);
    getchar();
    printf("Input Year Published: ");
    scanf("%d", &book.yearPublished);
    getchar();
    return book;
}

void updateRecord(char bookID[50]) {
    for (int i = 0;i < bookCount;i++) {
        if (strcmp(bookRecords[i].bookID, bookID) == 0) {
            displayIndividualRecord(bookRecords[i]);
            printf("Please input new record: \n");
            Book book = inputRecord(0);
            strcpy(book.bookID, bookRecords[i].bookID);
            char choice;
            printf("Do you want to update with these values? (y / n): ");
            choice = getchar();
            getchar();
            if (choice == 'y') {
                bookRecords[i] = book;
                displayAllRecords();
                return;
            } else {
                printf("Cancelled.\n");
                return;
            }
        }
    }
    printf("Not Found.\n");
}

void newRecord() {
    printf("Please input new record: \n");
    Book book = inputRecord(1);
    char choice;
    printf("Do you want to create with these values? (y / n): ");
    choice = getchar();
    getchar();
    if (choice == 'y') {
        bookRecords[bookCount] = book;
        bookCount++;
        displayAllRecords();
        return;
    } else {
        printf("Cancelled.\n");
        return;
    }
}

void deleteRecord(char bookID[50]) {
    for (int i = 0;i < bookCount;i++) {
        if (strcmp(bookRecords[i].bookID, bookID) == 0) {
            displayIndividualRecord(bookRecords[i]);
            char choice;
            printf("Do you want to delete? (y / n): ");
            choice = getchar();
            getchar();
            if (choice == 'y') {
                Book book;
                strcpy(book.bookID, "NULL");
                bookRecords[i] = book;
                displayAllRecords();
                return;
            } else {
                printf("Cancelled.\n");
                return;
            }
        }
    }
    printf("Not Found.\n");
}

void readFile() {
    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];
    int count = 0;

    filePointer = fopen("library.txt", "r");

    if (filePointer == NULL) {
        printf("Error Opening File");
        return;
    }

    while(fgets(buffer, bufferLength, filePointer)) {
        char year[255];
        sscanf(buffer, "%[^#]#%[^#]#%[^#]#%[^\n]\n", bookRecords[count].bookID, bookRecords[count].bookTitle, bookRecords[count].authorName, year);
        bookRecords[count].yearPublished = atoi(year);
        count++;
    }
    bookCount = count;
    fclose(filePointer);
}

void saveAndExit() {
    FILE* filePointer;
    filePointer = fopen("library.txt", "w");

    if (filePointer == NULL) {
        printf("Error Opening File");
        return;
    }

    for (int i = 0;i < bookCount;i++) {
        if(strcmp(bookRecords[i].bookID, "NULL") == 0) continue;
        fprintf(filePointer, "%s#%s#%s#%d\n", bookRecords[i].bookID, bookRecords[i].bookTitle, bookRecords[i].authorName, bookRecords[i].yearPublished);
    }
    fclose(filePointer);
}

int displayMenu() {
    system("cls");
    int x;
    puts("What do you want to do?");
    puts("1. Input book record\n2. Display book record (sorted)\n3. Update book record\n4. Erase book record\n5. Save and exit");
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
                newRecord();
                continue;
            }
            case 2: {
                displayAllRecords();
                continue;
            }
            case 3: {
                char input[50];
                printf("Input book id: ");
                scanf("%s", input);
                getchar();
                updateRecord(input);
                continue;
            }
            case 4: {
                char input[50];
                printf("Input book id: ");
                scanf("%s", input);
                getchar();
                deleteRecord(input);
                continue;
            }
            case 5: {
                saveAndExit();
                break;
            }
        }
        break;
    }

    return 0;
}