#include <stdio.h>

int main() {
    double l, b, h;

    scanf("%lf %lf %lf", &l, &b, &h);

    double luasSegiempat = 3 * b * l;
    double luasSegitiga = 1 * b * h;

    printf("%.3lf\n", luasSegiempat + luasSegitiga);

    return 0;
}