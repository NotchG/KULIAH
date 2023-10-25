#include <stdio.h>

int main() {
    long long int a, b, c,d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    printf("%s\n", a * b == c - d ? "True" : "False");
    return 0;
}