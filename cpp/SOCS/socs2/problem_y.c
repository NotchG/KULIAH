#include <stdio.h>

int main() {
    getchar();

    double x, y;
    double res[3];
    for (int i = 0;i < 3;i++) {
        scanf("%lf %lf", &x, &y);
        res[i] = y * x / 100;
    }
    for (int i = 0;i < 3;i++) {
        printf("%.2lf\n", res[i]);
    }
    return 0;
}