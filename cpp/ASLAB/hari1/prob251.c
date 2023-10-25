#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int goodDeeds[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &goodDeeds[i]);
    }

    int presents[N];
    for (int i = 0; i < N; i++) {
        presents[i] = 1; 
    }

    for (int i = 1; i < N; i++) {
        if (goodDeeds[i] > goodDeeds[i - 1]) {
            presents[i] = presents[i - 1] + 1;
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        if (goodDeeds[i] > goodDeeds[i + 1] && presents[i] <= presents[i + 1]) {
            presents[i] = presents[i + 1] + 1;
        }
    }
    int totalPresents = 0;
    for (int i = 0; i < N; i++) {
        totalPresents += presents[i];
    }

    printf("%d\n", totalPresents);

    return 0;
}