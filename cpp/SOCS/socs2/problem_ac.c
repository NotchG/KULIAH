#include <stdio.h>


int main() {
    int x;
    unsigned long long int res = 2;
    scanf("%d", &x);
    for (int i = 1;i < x;i++) {
        res += res;
    }   
    printf("%llu\n", res - 1);
    return 0;
}