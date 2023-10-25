#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1;i <= n;i++) {
        if (i > 2 && i != n) {
            for (int j = 0;j < i;j++) {
                if (j == 0 || j == i - 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        } else {
            for (int j = 0;j < i;j++) {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}