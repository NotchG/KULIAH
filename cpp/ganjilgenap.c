#include <stdio.h>

int main() {

    int angka;

    printf("Masukkan Angka: ");
    scanf("%i", &angka);

    if (angka % 2 == 0) {
        printf("Genap");
    } else {
        printf("Ganjil");
    }

    return 0;
}