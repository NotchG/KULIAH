#include <stdio.h>

int main() {
    char courseCode[5][100];
    int H1[5];
    int M1[5];
    int H2[5];
    int M2[5];

    for (int i = 0;i < 5;i++) {
        scanf("%s %d:%d-%d:%d", &courseCode[i], &H1[i], &M1[i], &H2[i], &M2[i]);
    }

    for (int i = 0;i < 5;i++) {
        printf("%s %02d:%.2d-%02d:%.2d\n", courseCode[i], H1[i] - 1, M1[i], H2[i] - 1, M2[i]);
    }

    return 0;
}