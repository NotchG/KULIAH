#include <stdio.h>

int main() {
    char x1[5];
    char x2[5];
    char x3[5];
    scanf("%s", x1);
    scanf("%s", x2);
    scanf("%s", x3);
    printf("%c\n", x1[1]);
    printf("%c\n", x2[1]);
    printf("%c\n", x3[1]);
    return 0;
}