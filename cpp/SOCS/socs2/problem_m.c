#include <stdio.h>

int main() {

    double x, y;

    scanf("%lf %lf", &x, &y);

    printf("%.2lf%%\n", (x / y) * 100);

    return 0;
}