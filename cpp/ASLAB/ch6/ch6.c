#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TABLE_SIZE 200

struct User {
    char name[100];
    char password[100];
    int balance;
    char role[20];
};

struct User *users[TABLE_SIZE];

unsigned int hashUser(char *user) {
    unsigned int res = 0;
    for (int i = 0;i < strlen(user);i++) {
        res += user[i];
    }
    return res % 200;
}

void initUsers() {
    for (int i = 0;i < TABLE_SIZE;i++) {
        users[i] = NULL;
    }
}

void insertUser(struct User *user) {
    int hash = hashUser(user->name);
    if (users[hash] == NULL) {
        users[hash] = user;
    }
}

struct User* findUser(char *user) {
    int hash = hashUser(user);
    if (users[hash] != NULL) {
        return users[hash];
    } else {
        return NULL;
    }
}

void readUsersFromFile() {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        struct User *user = malloc(sizeof(struct User));
        char name[100];
        char password[100];
        int balance;
        char role[20];
        sscanf(line, "%[^#]#%[^#]#%d#%s\n", name, password, &balance, role);
        strcpy(user->name, name);
        strcpy(user->password, password);
        strcpy(user->role, role);
        user->balance = balance;
        insertUser(user);
    }
    fclose(file);
}

int main() {
    initUsers();
    readUsersFromFile();
    while (1) {
        system("cls");
        char username[100];
        printf("Input Username >> ");
        scanf("%s", username);
        getchar();
        if (findUser(username) == NULL) {
            printf("User Not Found!");
            getchar();
        } else {
            printf("User Found");
            return 0;
        }
    }
    return 0;
}