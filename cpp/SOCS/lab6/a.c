#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        long long int b, c, d;
        scanf("%lld %lld %lld", &b, &c, &d);

        if (b < c + d && c < d + b && d < b + c) {
            printf("BISA\n");
        } else {
            printf("TIDAK BISA\n");
        }
    }

    return 0;
}
