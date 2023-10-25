#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20

char name[TABLE_SIZE][100];

unsigned int hash_func(char *str) {
    int ascii_sum = 0;
    for(int i = 0;i < strlen(str);i++) {
        int asciival = str[i];
        ascii_sum += asciival;
    }
    return ascii_sum % TABLE_SIZE;
}

void insertData(char *str) {
    int index = hash_func(str);
    strcpy(name[index], str);
}

int main() {
    insertData("Yonzi");
    insertData("Joane");
    insertData("Wening");

    int index = hash_func("Wening");
    printf("%s", name[index]);
    return 0;
}