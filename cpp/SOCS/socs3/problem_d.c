#include <stdio.h>

int main () {
    int t;
    scanf("%d", &t);
    int res[t];
    for (int i = 0; i < t;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        res[i] = (a * b )% 2 == 0 ? 1 : 0;
    }
    for (int i = 0;i < t;i++) {
        printf("Case #%d: %s\n", i + 1, res[i] == 1 ? "Party time!" : "Need more frogs");
    }
    return 0;
}