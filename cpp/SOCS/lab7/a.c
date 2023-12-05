#include <stdio.h>

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    getchar();
    int finalArr[m][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            finalArr[j][i] = 0;
        }
    }
    for (int i = 0;i < q;i++) {
        int x, y, a;
        scanf("%d %d %d", &x, &y, &a);
        finalArr[y][x] = a;
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            printf("%d", finalArr[j][i]);
            j == m - 1 ? printf("") : printf(" ");
        }
        printf("\n");
    }
    return 0;
}