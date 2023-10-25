#include <stdio.h>

int main() {
    getchar();

    double c;
    double r[3];
    double f[3];
    double k[3];

    for(int i = 0;i < 3;i++) {
        scanf("%lf",&c);
        r[i] = 0.8 * c;
        f[i] = 1.8 * c + 32;
        k[i] = c + 273;
    }
    for(int i = 0;i < 3;i++) {
        printf("%.2lf %.2lf %.2lf\n", r[i], f[i], k[i]);
    }
    return 0;
}