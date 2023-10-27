#include <stdio.h>
#include <string.h>
int main() {
    int jumlahTim;
    scanf("%d", &jumlahTim);
    getchar();
    int res[jumlahTim];
    memset(res, 0, jumlahTim * sizeof(int));
    for (int i = 0;i < jumlahTim * jumlahTim;i++) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            continue;
        }
        res[x - 1]++;
    }
    int incomplete = 0;
    for (int i = 0;i < jumlahTim;i++) {
        if (res[i] != jumlahTim) {
            incomplete++;
        }
    }
    printf("%d\n", incomplete);
    return 0;
}