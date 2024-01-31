#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("Masukkan String: ");
    scanf("%s", s);
    getchar();
    printf("Hasil Konversi: ");
    for (int i = strlen(s) - 1;i >= 0;i--) {
        int ascii = s[i];
        if (ascii >= 97) { ascii -= 32;} else { ascii += 32;}
        printf("%c", ascii);
    }
    printf("\n");
    return 0;
}