#include <stdio.h>

int main() {
    long long int a, b, c, d;
    long long int res[3];
    for(int i = 0;i < 3;i++){
        scanf(" (%lld+%lld)x(%lld-%lld)", &a, &b, &c, &d);
        res[i] = (a+b)*(c-d);
    }
    printf("%lld %lld %lld\n", res[0], res[1], res[2]);
    return 0;
}