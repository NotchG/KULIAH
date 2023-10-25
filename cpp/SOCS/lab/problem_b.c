#include <stdio.h>

int main() {

    double x, y;

    scanf("%lf %lf", &x, &y);

    printf("%.4lf%%\n", (y / x) * 100);

    return 0;
}