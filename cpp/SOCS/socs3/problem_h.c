#include <stdio.h>

int main() {
    char A, B, C;
    scanf("%c %c %c", &A, &B, &C);
    int a = A;
    int b = B;
    int c = C;
    int res[3];
    if (c < a && c < b) {
        res[0] = 3;
        if (b < a) {
            res[1] = 2;
            res[2] = 1;
        } else {
            res[1] = 1;
            res[2] = 2;
        }
    } else if (b < a && b < c) {
        res[0] = 2;
        if (a < c) {
            res[1] = 1;
            res[2] = 3;
        } else {
            res[1] = 3;
            res[2] = 1;
        }
    } else {
        res[0] = 1;
        if (b < c) {
            res[1] = 2;
            res[2] = 3;
        } else {
            res[1] = 3;
            res[2] = 2;
        }
    }
    printf("%d %d %d\n", res[0], res[1], res[2]);
    return 0;
}