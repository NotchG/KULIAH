#include <stdio.h>
#include <string.h>


int main() {
    char s[100];
    printf("String Input: ");
    scanf("%s", s);
    getchar();
    printf("String Output: ");
    for (int i = strlen(s) - 1;i >= 0;i--) {
        int x = s[i];
        if (x >= 97) {
            x -= 32;
        } else {
            x += 32;
        }
        printf("%c", x);
    }
    printf("\n");
    return 0;
}