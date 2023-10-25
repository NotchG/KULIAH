#include <stdio.h>

int main() {
    unsigned long long int x, y, z;
    scanf("%llu %llu %llu", &x, &y, &z);
    printf("%llu\n", x * y * z);
    return 0;
}