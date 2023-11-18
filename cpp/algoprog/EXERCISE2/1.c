#include <stdio.h>

int findMax(int arr[10]) {
    int max = arr[0];
    for (int i = 0;i < 10;i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int findMin(int arr[10]) {
    int min = arr[0];
    for (int i = 0;i < 10;i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[10];
    for (int i = 0;i < 10;i++) {
        scanf("%d", &arr[i]);
    }
    int max = findMax(arr);
    int min = findMin(arr);
    printf("Array: [");
    for (int i = 0;i < 10;i++) {
        if (i == 9) {
            printf("%d", arr[i]);
            continue;
        }
        printf("%d, ", arr[i]);
    }
    printf("]\n");
    printf("Max Value is %d.\n", max);
    printf("Min Value is %d.\n", min);
    return 0;
}