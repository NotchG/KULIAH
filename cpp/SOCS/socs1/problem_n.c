#include <stdio.h>

int main() {
    char n1[100];
    double t1;
    int u1;
    char n2[100];
    double t2;
    int u2;
    scanf("%s %lf %i %s %lf %i", &n1, &t1, &u1, &n2, &t2, &u2);
    printf("Name 1: %s\nHeight 1: %.2lf\nAge 1: %i\nName 2: %s\nHeight 2: %.2lf\nAge 2: %i\n", n1, t1, u1, n2, t2, u2);
    return 0;
}