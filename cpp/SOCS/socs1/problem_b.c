#include <stdio.h>
#include <string.h>

int main() {
    int n = 0;
    int m;
    int curr = 0;
    scanf("%d %d", &n, &m);
    int j = 0;
    while (j != m) {
        printf("%d\n", n);
        n++;
        j++;
    }
    return 0;
}