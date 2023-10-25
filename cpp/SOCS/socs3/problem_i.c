#include <stdio.h>

int main () {
    int t;
    scanf("%d", &t);
    int res[t];
    for (int i = 0; i < t;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        res[i] = ((a/100) * b) > c ? c : ((a/100) * b);
    }
    for (int i = 0;i < t;i++) {
        printf("Case #%d: %d\n", i + 1, res[i]);
    }
    return 0;
}