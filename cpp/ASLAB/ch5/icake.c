#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Cake {
    char id[10];
    char name[100];
    char flavor[100];
    char type[50];
    int stocks;
    float price;
    struct Cake* next;
    struct Cake* prev;
};

void displayLogo() {
    puts(" ____       ___    __    _  _  ____ ");
    puts("(_  _)___  / __)  /__\\  ( )/ )( ___)");
    puts(" _)(_(___)( (__  /(__)\\  )  (  )__) ");
    puts("(____)     \\___)(__)(__)(_)\\_)(____)");
    puts("===================================================================================================");
}

void insertCake(struct Cake** head, struct Cake* newCake) {
    if (*head == NULL) {
        *head = newCake;
        newCake->prev = NULL;
        newCake->next = NULL;
    } else {
        struct Cake* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCake;
        newCake->prev = current;
        newCake->next = NULL;
    }
}

void writeToFile(struct Cake* head) {
    FILE *file = fopen("cake.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    struct Cake* current = head;
    while (current != NULL) {
        fprintf(file, "%s#%s#%s#%s#%d#%.2f\n",current->id, current->name, current->flavor, current->type, current->stocks, current->price);
        current = current->next;
    }
    
    fclose(file);
}

void readFromFile(struct Cake** head) {
    FILE *file = fopen("cake.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char id[10];
    char name[100];
    char flavor[100];
    char type[50];
        int stocks;
        float price;
        
        sscanf(line, "%[^#]#%[^#]#%[^#]#%[^#]#%d#%f\n", id, name, flavor, type, &stocks, &price);
        
        struct Cake* newCake = (struct Cake*)malloc(sizeof(struct Cake));
        strcpy(newCake->id, id);
        strcpy(newCake->name, name);
        strcpy(newCake->flavor, flavor);
        strcpy(newCake->type, type);
        newCake->stocks = stocks;
        newCake->price = price;

        insertCake(head, newCake);
    }
    
    fclose(file);
}

int main() {
    srand(time(NULL));
    struct Cake* cakeList = NULL;
    readFromFile(&cakeList);
    while (1) {
        system("cls");
        char command[20];
        displayLogo();
        puts("For insert input: insert [name]-[flavor]-[type]-[stocks]-[price]");
        puts("Constraint:");
        puts("- Name must end with ' Cake'");
        puts("- Flavor must be 3 - 15 characters long");
        puts("- Type must be: Premium, Specialty, Classic");
        puts("- Stocks must be more than 0");
        puts("- Price must be more than 80");
        puts("Example: insert Bolu Cake-Chocolate-Classic-10-80");
        puts("\nFor delete input: delete [id]");
        puts("For search input: search [id]");
        puts("Example: delete IC001");
        puts("\nFor view input: view");
        puts("For exit input: exit");
        puts("==================================================================================================");
        printf(">> ");
        scanf("%s", command);
        getchar();
        
        if (strcmp(command, "insert") == 0) {
            char input[100];
            printf("Enter cake details (name-flavor-type-stocks-price): ");
            scanf("%[^\n]", input);
            getchar();

            char arr[5][100];
            int i = 0;

            char *token = strtok(input, "-");
            while (token != NULL) {
                printf("%s", token);
                strcpy(arr[i], token);
                i++;
                token = strtok(NULL, "-");
            }
            int stocks = atoi(arr[3]);
            float price = atoi(arr[4]);
            char ID[10];
            struct Cake* newCake = (struct Cake*)malloc(sizeof(struct Cake));
            sprintf(ID, "IC%d%d%d", rand()%10, rand()%10, rand()%10);
            strcpy(newCake->id, ID);
            strcpy(newCake->name, arr[0]);
            strcpy(newCake->flavor, arr[1]);
            strcpy(newCake->type, arr[2]);
            newCake->stocks = stocks;
            newCake->price = price + (price * 15/100);

            insertCake(&cakeList, newCake);
            writeToFile(cakeList);
        } 
        else if (strcmp(command, "view") == 0) {
            system("cls");
            displayLogo();
            struct Cake* current = cakeList;
            int i = 1;
            puts("===================================================================================================");
            puts("|No.  | ID    | Name                 | Flavor               | Type       | Stock      | Price     |");
            puts("|=====|=======|======================|======================|============|============|===========|");
            while (current != NULL) {
                char no[10];
                char stock[20];
                char price[20];
                sprintf(stock, "%d", current->stocks);
                sprintf(price, "%.2f", current->price);
                sprintf(no, "%d", i);
                printf("|%d", i);
                for (int j = 0;j < 5 - strlen(no);j++) {
                    printf(" ");
                }
                printf("| %s | %s", current->id,  current->name);
                for (int j = 0;j < 20 - strlen(current->name);j++) {
                    printf(" ");
                }
                printf(" | %s", current->flavor);
                for (int j = 0;j < 20 - strlen(current->flavor);j++) {
                    printf(" ");
                }
                printf(" | %s", current->type);
                for (int j = 0;j < 10 - strlen(current->type);j++) {
                    printf(" ");
                }
                printf(" | %s", stock);
                for (int j = 0;j < 10 - strlen(stock);j++) {
                    printf(" ");
                }
                printf(" | %s", price);
                for (int j = 0;j < 9 - strlen(price);j++) {
                    printf(" ");
                }
                printf(" |\n");
                current = current->next;
                i++;
            }
            puts("===================================================================================================\n");
            printf("Press enter to continue...\n");
            getchar();
        } 
        else if (strcmp(command, "search") == 0) {
            char searchId[10];
            printf("Enter the ID to search for: \n");
            scanf("%s", searchId);
            getchar();
            displayLogo();
            puts("===================================================================================================");
            puts("|No.  | ID    | Name                 | Flavor               | Type       | Stock      | Price     |");
            puts("|=====|=======|======================|======================|============|============|===========|");
            struct Cake* current = cakeList;
            while (current != NULL) {
                if (strcmp(current->id, searchId) == 0) {
                    char no[10];
                char stock[20];
                char price[20];
                sprintf(stock, "%d", current->stocks);
                sprintf(price, "%.2f", current->price);
                sprintf(no, "%d", 1);
                printf("|%d", 1);
                for (int j = 0;j < 5 - strlen(no);j++) {
                    printf(" ");
                }
                printf("| %s | %s", current->id,  current->name);
                for (int j = 0;j < 20 - strlen(current->name);j++) {
                    printf(" ");
                }
                printf(" | %s", current->flavor);
                for (int j = 0;j < 20 - strlen(current->flavor);j++) {
                    printf(" ");
                }
                printf(" | %s", current->type);
                for (int j = 0;j < 10 - strlen(current->type);j++) {
                    printf(" ");
                }
                printf(" | %s", stock);
                for (int j = 0;j < 10 - strlen(stock);j++) {
                    printf(" ");
                }
                printf(" | %s", price);
                for (int j = 0;j < 9 - strlen(price);j++) {
                    printf(" ");
                }
                printf(" |\n");
                    break;
                }
                current = current->next;
            }
            if (current == NULL) {
                puts("No data found..");
            }
            puts("===================================================================================================\n");
            printf("Press enter to continue...\n");
            getchar();
        } 
        else if (strcmp(command, "delete") == 0) {
            char deleteId[10];
            printf("Enter the ID to delete: ");
            scanf("%s", deleteId);
            getchar();
            displayLogo();
            puts("===================================================================================================");
            puts("|No.  | ID    | Name                 | Flavor               | Type       | Stock      | Price     |");
            puts("|=====|=======|======================|======================|============|============|===========|");
            struct Cake* current = cakeList;
            while (current != NULL) {
                if (strcmp(current->id, deleteId) == 0) {
                    char no[10];
                char stock[20];
                char price[20];
                sprintf(stock, "%d", current->stocks);
                sprintf(price, "%.2f", current->price);
                sprintf(no, "%d", 1);
                printf("|%d", 1);
                for (int j = 0;j < 5 - strlen(no);j++) {
                    printf(" ");
                }
                printf("| %s | %s", current->id,  current->name);
                for (int j = 0;j < 20 - strlen(current->name);j++) {
                    printf(" ");
                }
                printf(" | %s", current->flavor);
                for (int j = 0;j < 20 - strlen(current->flavor);j++) {
                    printf(" ");
                }
                printf(" | %s", current->type);
                for (int j = 0;j < 10 - strlen(current->type);j++) {
                    printf(" ");
                }
                printf(" | %s", stock);
                for (int j = 0;j < 10 - strlen(stock);j++) {
                    printf(" ");
                }
                printf(" | %s", price);
                for (int j = 0;j < 9 - strlen(price);j++) {
                    printf(" ");
                }
                printf(" |\n");
                    break;
                }
                current = current->next;
            }
            puts("===================================================================================================\n");
            if (current == NULL) {
                puts("No data found..");
                printf("Press enter to continue...\n");
                getchar();
            } else {
                puts("Are you sure you want to delete this cake (y/n)");
            printf(">>");
            char delete = getchar();
            getchar();
            if (delete == 'y') {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                writeToFile(cakeList);
                puts("Successfully deleted!");
                printf("Press enter to continue...\n");
                getchar();
            }
            }
            
        } 
        else if (strcmp(command, "exit") == 0) {
            system("cls");
            displayLogo();
            puts("Thank you for using this program");
            puts("________________________________");
            break;
        } 
        else {
            system("cls");
            printf("Command not found\n");
            printf("Press enter to continue...\n");
            getchar();
        }
    }

    return 0;
}