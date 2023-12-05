#include <stdio.h>

int main() {
    int T;


    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;

      
        scanf("%d", &N);

        int windMap[N][N];


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &windMap[i][j]);
            }
        }

     
        long long columnSums[N]; 
        for (int j = 0; j < N; j++) {
            columnSums[j] = 0;
            for (int i = 0; i < N; i++) {
                columnSums[j] += windMap[i][j];
            }
        }

     
        printf("Case #%d:", t);
        for (int j = 0; j < N; j++) {
            printf(" %lld", columnSums[j]);
        }
        printf("\n");
    }

    return 0;
}
