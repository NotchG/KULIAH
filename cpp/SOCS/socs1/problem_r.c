#include <stdio.h>

int main() {
    char n1[100];
    int u1;
    char n2[100];
    char n3;
    scanf("%[^\n]", &n1);
    scanf("\n%[^\n]", &n2);
    scanf("\n%c %i", &n3, &u1);
    printf("Id    : %s\n", n1);
    printf("Name  : %s\n", n2);
    printf("Class : %C\n", n3);
    printf("Num   : %i\n", u1);
    return 0;
}