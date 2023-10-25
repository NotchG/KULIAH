#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    a = a * 20/100;
    b = b * 30/100;
    c = c * 50/100;

    printf("%.2lf\n", a + b +c);
    return 0;
}