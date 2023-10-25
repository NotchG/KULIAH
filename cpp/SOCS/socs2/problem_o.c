#include <stdio.h>

int main() {
    int x, y;
    int res[4];
    for(int i = 0;i < 4;i++){
        scanf("%d %d", &x, &y);
        res[i] = x * y;
    }
    for(int i = 0;i < 4;i++){
        printf("%d\n", res[i]);
    }
    return 0;
}