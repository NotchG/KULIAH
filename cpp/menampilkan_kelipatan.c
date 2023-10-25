#include <stdio.h>

int main() {
    
    int bilangan;

    printf("Masukkan Bilangan: ");
    scanf("%i", &bilangan);

    for (int i = 1;i <= bilangan;i++) {
        if (bilangan % i == 0) {
            printf("%i\n", i);
        }
    }
    
    return 0;
}