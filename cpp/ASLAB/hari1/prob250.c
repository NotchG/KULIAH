#include <stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);
    long long int mountainHeights[n];
    long long int res[n];
    
    for (int i = 0;i < n;i++) {
        scanf("%lld", &mountainHeights[i]);
    }

     for (int i = 0;i < n;i++) {
        res[i] = 0;
        int y = mountainHeights[i] - mountainHeights[i + 1];
        if (y > 0) {
            res[i]++;
        }
        for (int j = i + 2;j < n;j++) {
            int p = mountainHeights[i] - mountainHeights[j];
            if (p < 0) {
                res[i]++;
                break;
            }
            if (p < y) {
                res[i]++;
                y = p;
            }
        }
    }
    res[n - 1] = 0;
    for (int i = 0; i < n;i++) {
        if (i != n-1) {
            printf("%lld ", res[i]);
        } else {
            printf("%lld", res[i]);
        }
        
    }
    printf("\n");
    return 0;
}