#include <stdio.h>
#include <string.h>

int main() {
    
    char str[100];
    scanf("%[^\n]",&str);
    int count = 0;
    for (int i = 0;i < strlen(str);i++) {
        if (str[i] == 'a' || str[i] == 'A') {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}