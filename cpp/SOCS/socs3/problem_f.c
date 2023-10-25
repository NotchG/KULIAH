#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c) {
        printf("Daging\n");
        if (b > c) {
            printf("Sayur\n");
            printf("Telur\n");
        } else {
            printf("Telur\n");
            printf("Sayur\n");
        }
    } else if (b > a && b > c) {
        printf("Sayur\n");
        if (a > c) {
            printf("Daging\n");
            printf("Telur\n");
        } else {
            printf("Telur\n");
            printf("Daging\n");
        }
    } else {
        printf("Telur\n");
        if (a > b) {
            printf("Daging\n");
            printf("Sayur\n");
        } else {
            printf("Sayur\n");
            printf("Daging\n");
        }
    }
    return 0;
}