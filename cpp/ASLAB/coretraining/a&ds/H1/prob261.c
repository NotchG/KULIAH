#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    long long transaction = 0;

    for (int i = 0;i < T;i++) {
        long long x;
        char plusorminus;
        scanf("%c %lld", &plusorminus, &x);
        getchar();
        if (plusorminus == '+') {
            transaction += x;
        } else {
            transaction -= x;
        }
    }

    if (transaction == 0) {
        printf("perfectly balanced as all things should be\n");
    } else {
        printf("utterly chaotic as nothing should be\n");
    }
    return 0;
}