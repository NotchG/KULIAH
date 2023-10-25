#include<stdio.h>
int main() {
    int Z;
    scanf("%d", &Z);
    int res[Z][10][10];
    int N[Z];
    for (int l = 0;l < Z;l++) {
        int a[10][10], b[10][10], c[10][10], d[10][10], e[10][10], n;
    scanf("%d", & n);
    N[l] = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", & a[i][j]);
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", & b[i][j]);
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", & d[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            e[i][j] = 0;
            for (int k = 0; k < n; k++) {
                e[i][j] += c[i][k] * d[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[l][i][j] = e[i][j];
        }
    }
    }

    for (int l = 0;l < Z;l++) {
        printf("Case #%d:\n",l+1);
        for (int i = 0; i < N[l]; i++) {
        for (int j = 0; j < N[l]; j++) {
            if (j == N[l] - 1) {
                printf("%d", res[l][i][j]);
            } else {
                printf("%d ", res[l][i][j]);
            }
        }
        printf("\n");

    }
    }
    return 0;
}