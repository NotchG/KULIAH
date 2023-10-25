#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    char ID[10];
    char author[20];
    char title[30];
    int price;
};

struct Book books[30];
int numOfBooks;

int bookCompareAsc(const void* a, const void* b) {
    const struct Book *p1 = (struct Book *)a;
    const struct Book *p2 = (struct Book *)b;
    if (strcmp(p1->author, p2->author) == 0) {
        if (p1->price <  p2->price) {
            return -1;
        } else if (p1->price >  p2->price) {
            return 1;
        }
    } else if (strcmp(p1->author, p2->author) < 0) {
        return -1;
    } else {
        return 1;
    }
}

int bookCompareDsc(const void* a, const void* b) {
    const struct Book *p1 = (struct Book *)a;
    const struct Book *p2 = (struct Book *)b;
    if (strcmp(p1->author, p2->author) < 0) {
        return 1;
    } else if (strcmp(p1->author, p2->author) > 0) {
        return -1;
    } else {
        if (p1->price <  p2->price) {
            return 1;
        } else if (p1->price >  p2->price) {
            return -1;
        }
    }
}


void displayLogo() {
    puts("    __ _ _                 _       ___  ___ _    ");
    puts("   / /(_) |__  _ __ __ _  | |__   /___\\/___\\ | __");
    puts("  / / | | '_ \\| '__/ _` | | '_ \\ //  ///  // |/ /");
    puts(" / /__| | |_) | | | (_| | | |_) / \\_// \\_//|   < ");
    puts(" \\____/_|_.__/|_|  \\__,_| |_.__/\\___/\\___/ |_|\\_\\");
    puts("                                                 ");
}

int displayMenu() {
    while (1) {
        system("cls");
        displayLogo();
        puts(" +========================================================+");
        puts(" |                                                        |");
        puts(" |    1. View Book List                                   |");
        puts(" |    2. Add Book                                         |");
        puts(" |    3. Remove Book                                      |");
        puts(" |    4. Exit                                             |");
        puts(" |                                                        |");
        puts(" +========================================================+");
        int opt;
        printf(">> ");
        scanf("%d", &opt);
        getchar();
        if (opt >= 1 && opt <= 4) {
            return opt;
        }
    }
    
}

int getBooks() {
    int length = 0;
    char *filename = "data.txt";
    FILE *fp = fopen(filename, "r");
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    memset(books, 0, sizeof(books));
    numOfBooks = 0;
    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 0;
    } else {
        while (fgets(buffer, MAX_LENGTH, fp)) {
            struct Book *book = &books[numOfBooks];
            char priceStr[10];
            sscanf(buffer, "%[^#]#%[^#]#%[^#]#%s", book->ID, book->author, book->title, priceStr);
            book->price = atoi(priceStr);
            numOfBooks++;
        }
    }
    fclose(fp);
}

void viewBookList() {
    system("cls");
    getBooks();
    qsort(books, numOfBooks, sizeof(const struct Book), bookCompareDsc);
        printf("\nSorted by Author & Price\n\n");
        puts(" +==============================================================================+");
        puts(" | ID      | Author               | Title                          | Price      |");
        puts(" +==============================================================================+");
        for (int i = 0;i < numOfBooks;i++) {
            struct Book *book = &books[i];
            char priceStr[10];
            sprintf(priceStr, "%d", book->price);
            printf(" | %s | ", book->ID);
            for (int i = 0;i < 20 - strlen(book->author);i++) {
                printf(" ");
            }
            printf("%s | ", book->author);
            for (int i = 0;i < 30 - strlen(book->title);i++) {
                printf(" ");
            }
            printf("%s | ", book->title);
            for (int i = 0;i < 10 - strlen(priceStr);i++) {
                printf(" ");
            }
            printf("%s |", priceStr);
            printf("\n");
        }
        puts(" +==============================================================================+");
}

void viewBookPage() {
    viewBookList();
    puts("Press any key to continue");
    getchar();
}

void deleteBookPage() {
    char ID[10];
    int idx = -1;
    while (1) {
        viewBookList();
        puts("\n[9] back");
        printf("Remove Book [ e.g. BOOK452]: ");
        scanf("%s", ID);
        getchar();
        if (ID[0] == '9');
        for (int i = 0;i < numOfBooks;i++) {
            if (books[i].ID[4] == ID[4] && books[i].ID[5] == ID[5] && books[i].ID[6] == ID[6]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            printf("Invalid Book ID...");
            getchar();
            continue;
        }
        char *filename = "data.txt";
        FILE *fp = fopen(filename, "w");
        for (int i = 0;i < numOfBooks;i++) {
            if (i == idx) continue;
            fprintf(fp, "%s#%s#%s#%d\n", books[i].ID, books[i].author, books[i].title, books[i].price);
        }
        fclose(fp);
    }
}

void addBookPage() {
    char ID[10] = "";
    char author[100];
    char title[100];
    int price = 0;
    author[0] = 0;
    title[0] = 0;
    while (1) {
        printf(" Input author's name [ >= 5 characters & <= 20 characters]: ");
            scanf("%[^\n]", author);
            getchar();
            if (strlen(author) >= 5 && strlen(author) <= 20) {
                break;
            }
            printf("Author's name must be [ >= 5 characters & <= 20 characters]...\n\n");
    }

    while (1) {
        printf(" Input book's title [must be filled]: ");
            scanf("%[^\n]", title);
            getchar();
            if (strlen(title) != 0) {
                break;
            }
            printf("Book's title [must be filled]...\n\n");
    }

    while (1) {
        printf(" Input book's price [ >=1000 ]: ");
            scanf("%d", &price);
            getchar();
            if (price >= 1000) {
                break;
            }
            printf("book's price must be [ >=1000 ]...\n\n");
    }
    sprintf(ID, "BOOK%d%d%d", rand() % 10, rand() % 10, rand() % 10);
    char *filename = "data.txt";
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%s#%s#%s#%d\n", ID, author, title, price);
    fclose(fp);
    puts("\n Newly added book's details:");
    puts(" +----------------------------------------+");
    printf(" | ID    : %s", ID);
    for (int i = 0;i < 30 - strlen(ID);i++) {
        printf(" ");
    }
    printf(" |\n");
    printf(" | Author: %s", author);
    for (int i = 0;i < 30 - strlen(author);i++) {
        printf(" ");
    }
    char priceStr[10];
    sprintf(priceStr, "%d", price);
    printf(" |\n");
    printf(" | Title : %s", title);
    for (int i = 0;i < 30 - strlen(title);i++) {
        printf(" ");
    }
    printf(" |\n");
    printf(" | Price : %d", price);
    for (int i = 0;i < 30 - strlen(priceStr);i++) {
        printf(" ");
    }
    printf(" |\n");
    puts(" +----------------------------------------+\n");
    puts("Press any key to continue");
    getchar();
}

int main() {
    while (1) {
        int menuOpt = displayMenu();
    switch(menuOpt) {
        case 1: {
            viewBookPage();
            break;
        }
        case 2: {
            addBookPage();
            break;
        }
        case 3: {
            deleteBookPage();
            break;
        }
        case 4: {
            return 0;
            break;
        }
    }
    }
    return 0;
}