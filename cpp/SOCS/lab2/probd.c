#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int k[n];
    int currPos = 0;
    for (int i = 0;i < n;scanf("%d", &k[i++]));
    for (int i = 0;i < n;i++) {
        currPos += k[i];
        if (currPos >= 40) {
            currPos = currPos % 40;
        }
        if (currPos == 30) {
            currPos = 10;
        } else if (currPos == 12) {
            currPos = 28;
        } else if (currPos == 35) {
            currPos = 7;
        }
    }
    printf("%d\n", currPos);
    return 0;
}