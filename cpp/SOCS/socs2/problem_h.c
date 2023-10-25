#include <stdio.h>

int main() {
    double a, b, c, d;

    double res[3];

    for (int i = 0;i < 3;i++) {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        double aRes = a/1 * 2;
        double bRes = b/2 * 4;
        double cRes = c/3 * 6;
        double dRes = d/4 * 4;
        res[i] = aRes + bRes + cRes + dRes;
    }

    for (int i = 0;i < 3;i++) {
        printf("%.2lf\n", res[i]);
    }

    return 0;
}