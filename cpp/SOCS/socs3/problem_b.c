#include <stdio.h>

int main () {
    int t;
    scanf("%d", &t);
    int res[t];
    for (int i = 0; i < t;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        res[i] = (b + c) >= a ? 1 : 0;
    }
    for (int i = 0;i < t;i++) {
        printf("Case #%d: %s\n", i + 1, res[i] == 1 ? "yes" : "no");
    }
    return 0;
}