#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    char res[t][100];
    int n[t];
    for (int i = 0;i < t;i++) {
        scanf("%d", &n[i]);
        getchar();
        scanf("%[^\n]", &res[i]);
    }
    for (int i = 0;i < t;i++) {
        printf("Case #%d: ", i + 1);
        for (int j = 0;j < n[i];j++) {
            int x = res[i][j];
            if (x > 96 && x < 123) {
                printf("%c", res[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}