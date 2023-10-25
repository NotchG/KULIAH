#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 20

// kelemahan dari hash map == hash collision
// hash double linked list
// chaining hash / linear probing

// bibi = 6
// frara = 6

char name[TABLE_SIZE][100];

void initializeTable() {
    for (int i = 0;i < TABLE_SIZE;i++) {
        strcpy(name[i], "");
    }
}

unsigned int hash_func(char *str) {
    unsigned int ascii_sum = 0;
    for (int i = 0;i < strlen(str);i++) {
        int asc_value = str[i];
        ascii_sum += asc_value;
    }
    return ascii_sum % TABLE_SIZE;
}

void hashLookup(char *str) {
    int index = hash_func(str);
    if (strcmp(name[index], "") == 0) {
        printf("No user found");
    } else {
        printf("%s", name[index]);
    }
}

void insertData(char *str) {
    int index = hash_func(str);
    if (strcmp(name[index], "") == 0) {
        strcpy(name[index], str);
    } else {
        
    }
}

int main() {
    initializeTable();
    insertData("Clive");
    insertData("Vido");
    insertData("Dalia");
    insertData("Frarar");
    insertData("BraBra");
    insertData("bibi");
    
    char user[100];
    scanf("%s", user);
    hashLookup(user);
    return 0;
}