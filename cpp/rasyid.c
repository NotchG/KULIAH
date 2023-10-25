#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    char a;
    char choice;
    scanf("%[^\n]\n", str);
    a = getchar();
    getchar();
    printf("Want to upper or lower (u/l): ");
    choice = getchar();
    getchar();
    for (int i = 0;i < strlen(str);i++) {
        if (str[i] == a) {
            if (choice == 'u') {
                str[i] = toupper(str[i]);
            } else if (choice == 'l') {
                str[i] = tolower(str[i]);
            }
            
        }
    }
    printf("%s", str);
    return 0;
}