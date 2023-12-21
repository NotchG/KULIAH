#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define algo "ANJAY.txt"

typedef struct {
    int id;
    char title[101];
    char author[101];
    int year;
} book;

void input(book *data) {
    printf("Enter Book Id: ");
    scanf("%d", &data->id);
    printf("Enter Book Title: ");
    getchar(); 
    scanf("%[^\n]", data->title);
    printf("Enter Book Author: ");
    getchar();
    scanf("%[^\n]", data->author);
    printf("Enter Book Year Published: ");
    scanf("%d", &data->year);
}

void displaySorted(book data[], int numBooks) {
    for (int i = 0; i < numBooks - 1; i++) {
        for (int j = 0; j < numBooks - 1 - i; j++) {
            if (strcmp(data[j].title, data[j + 1].title) > 0) {
                book temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("Book Record: \n");
    for (int i = 0; i < numBooks; i++) {
        printf("Book ID: %d\n", data[i].id);
        printf("Book Title: %s\n", data[i].title);
        printf("Author Name: %s\n", data[i].author);
        printf("Book Year Published: %d\n", data[i].year);
    }
}

void update(book data[], int numBooks) {
    int bookId;
    int found = 0;

    printf("Enter Book ID for Update : ");
    scanf("%d", &bookId);

    for (int i = 0; i < numBooks; i++) {
        if (data[i].id == bookId) {
            printf("Old Record: \n");
            printf("Book ID: %d\n", data[i].id);
            printf("Book Title: %s\n", data[i].title);
            printf("Author Name: %s\n", data[i].author);
            printf("Book Year Published: %d\n", data[i].year);
            input(&data[i]);
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book Not Found\n");
    }
}

void erase(book data[], int *numBooks) {
    int bookId;
    int found = 0;

    printf("Enter Book ID to Erase: ");
    scanf("%d", &bookId);

    for (int i = 0; i < *numBooks; i++) {
        if (data[i].id == bookId) {
            for (int j = i; j < *numBooks - 1; j++) {
                data[j] = data[j + 1];
            }
            (*numBooks)--;
            found = 1;
            printf("Book Successfully Erased\n");
            break;
        }
    }

    if (!found) {
        printf("Book Not Found\n");
    }
}

void saveExit(book data[], int numBooks) {
    FILE *file = fopen(algo, "w");

    if (file == NULL) {
        printf("Error Opening File :(\n");
        exit(1);
    }

    for (int i = 0; i < numBooks; i++) {
        fprintf(file, "%d#%s#%s#%d\n", data[i].id, data[i].title, data[i].author, data[i].year);
    }

    fclose(file);
    printf("File '%s' written successfully.\n", algo);
}

void read(book data[], int *numBooks) {
    FILE *file = fopen(algo, "r");
    if (file == NULL) {
        printf("File '%s' is not found. Try creating a new file...\n", algo);
        return;
    }
    while (fscanf(file, "%d#%99[^#]#%99[^#]#%d\n", &data[*numBooks].id, data[*numBooks].title,
                  data[*numBooks].author, &data[*numBooks].year) == 4) {
        (*numBooks)++;
        if (*numBooks >= MAX_LINES) {
            printf("Maximum number of books reached.\n");
            break;
        }
    }
    fclose(file);
    printf("File '%s' read successfully.\n", algo);
}

int main() {
    book *list = (book *)malloc(sizeof(book) * MAX_LINES);

    int numBooks = 0;
    int choice;

    do {
        printf("Option You Can Do: \n");
        printf("1. Input book record\n");
        printf("2. Display book record\n");
        printf("3. Update book record\n");
        printf("4. Erase book record\n");
        printf("5. Save and Exit\n");
        printf("Choose Your Option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            input(&list[numBooks]);
            numBooks++;
            break;
        case 2:
            displaySorted(list, numBooks);
            break;
        case 3:
            update(list, numBooks);
            break;
        case 4:
            erase(list, &numBooks);
            break;
        case 5:
            saveExit(list, numBooks);
            break;
        default:
            printf("Choose an option from the menu!\n");
        }
    } while (choice != 5);

    free(list);
    return 0;
}