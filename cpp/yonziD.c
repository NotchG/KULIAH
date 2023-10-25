#include <stdio.h>

int main() {
    double n[4];
    double p[4];
    double res[4];

    for(int i = 0;i < 4;i++) {
        scanf("%lf %lf", &n[i], &p[i]);
        if (n[i] == 0) {
            res[i] = p[i];
        } else {
            res[i] = p[i] / (1-(n[i]/100));
        }
        
    }

    for (int i = 0;i < 4;i++) {
        printf("$%.2lf\n",res[i]);
    }
    return 0;
}