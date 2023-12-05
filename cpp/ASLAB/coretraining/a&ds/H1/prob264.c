#include <stdio.h>
#include <stdlib.h>

int main() {
    int time;
    char timeFormat[5];
    scanf("%d %s", &time, timeFormat);

    int maxStorage;
    int numberOfCarts;
    int weights[200];

    scanf("%d", &maxStorage);
    scanf("%d", numberOfCarts);

    int i = 0;
    while (1) {
        char str[100];
        scanf("%s", str);
        if (atoi(str) == 0) {
            break;
        } else {
            weights[i] = atoi(str);
            i++;
        }
    }
    for (int j = 0;j < i+1;j++) {
        printf("%d ", weights[j]);
    }
    return 0;
}