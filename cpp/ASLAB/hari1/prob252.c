#include <stdio.h>

int main() {
    int row;
    int column;
    int res = 0;
    scanf("%d %d", &row, &column);
    int plot[column][row];
    for(int i = 0;i < column;i++) {
        for(int j = 0;j < row;j++) {
            scanf("%d", &plot[j][i]);
            getchar();
        }
    }
    for(int i = 0;i < column;i++) {
        for (int j = 0;j < row;j++) {
             if (plot[i][j] == 1) {
                if (i == 0 || plot[i - 1][j] == 0) {
                    res++;
                }
                if (i == row - 1 || plot[i + 1][j] == 0) {
                    res++;
                }
                if (j == 0 || plot[i][j - 1] == 0) {
                    res++;
                }
                if (j == column - 1 || plot[i][j + 1] == 0) {
                    res++;
                }
            }

        }
    }
    printf("%d\n", res);
    return 0;
}