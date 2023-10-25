#include <stdio.h>

int main() {
    int x;
    unsigned long long int res = 0;
    scanf("%d", &x);
    for(int i = 0;i < x;i++) {
        res += 100 + (50 * i);
    }
    printf("%llu\n", res);
    return 0;
}