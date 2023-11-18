#include <stdio.h>

void swap(char *A, char *B) {
    char C;
    C = *A;
    *A = *B;
    *B = C;
}

int main() {
    char X, Y;
    X = 'S';
    Y = 'D';
    swap(&X, &Y);
    printf("X = %c Y = %c", X, Y);
    return 0;
}