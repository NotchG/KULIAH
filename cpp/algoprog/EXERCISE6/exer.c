#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char bookID[50];
    char bookTitle[255];
    char authorName[255];
    int yearPublished;
} Book;

Book bookRecords[100];
int bookCount;

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
    for(int i = 0;i < bookCount;i++) {
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

void deleteRecord(char bookID[50]) {
    for (int i = 0;i < bookCount;i++) {
        if (strcmp(bookRecords[i].bookID, bookID) == 0) {
            displayIndividualRecord(bookRecords[i]);
            char choice;
            printf("Do you want to update with these values? (y / n): ");
            choice = getchar();
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

int main() {
    readFile();

    displayAllRecords();

    return 0;
}