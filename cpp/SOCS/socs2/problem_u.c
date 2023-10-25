#include <stdio.h>

int main() {
    double x, y;
    double res[3];
    for (int i = -1; i < 3;i++) {
        if(i == -1) {
            getchar();
        } else {
            scanf("%lf %lf", &x, &y);
            res[i] = x * y / 360;
        }
    }
    for (int i = 0;i < 3;i++) {
        printf("%.2lf\n", res[i]);
    }
    return 0;
}