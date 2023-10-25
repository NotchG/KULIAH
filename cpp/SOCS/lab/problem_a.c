#include <stdio.h>

int main() {
    int x;

    scanf("%i", &x);

    printf("%i plus %i is %i\n"
    "minus one is %i\n", x, x, x + x, x + x - 1);

    return 0;
}