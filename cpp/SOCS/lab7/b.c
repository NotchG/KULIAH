#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int T2;
        scanf("%d", &T2);
        int res[T2];

        for (int m = 0; m < T2; m++) {
            res[m] = 0;
        }

        for (int j = 0; j < T2; j++) {
            for (int k = 0; k < T2; k++) {
                int xxx;
                scanf("%d", &xxx);
                res[k] += xxx;
            }
        }

        printf("Case #%d:", i + 1);
        for (int m = 0; m < T2; m++) {
            printf(" %d", res[m]);
        }
        printf("\n"); 
    }

    return 0;
}
