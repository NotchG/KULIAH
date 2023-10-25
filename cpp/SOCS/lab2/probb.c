#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int k[n];
    int currPos = 0;
    for (int i = 0;i < n;scanf("%d", &k[i++]));
    for (int i = 0;i < n;i++) {
        currPos += k[i];
        switch (currPos) {
            case 9: currPos = 21; break;
            case 33: currPos = 42; break;
            case 76: currPos = 92; break;
            case 53: currPos = 37; break;
            case 80: currPos = 59; break;
            case 97: currPos = 88; break;
        }
    }
    printf("%d\n", currPos);
    return 0;
}