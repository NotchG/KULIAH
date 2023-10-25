#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void pyramid(int x) {
    int rows = x;

    bool isEven = rows % 2 == 0;

    if (isEven) {
        int curr = 2;
        int space = rows / 2;
        while (curr <= rows) {
            for(int i = 0;i < space;i++) {
                printf(" ");
            }
            space--;
            for(int i = 0;i < curr;i++) {
                printf("*");
            }
            printf("\n");
            curr += 2;
        }
    } else if (!isEven) {
        int curr = 1;
        int space = (rows - 1) / 2;
        while (curr <= rows) {
            for(int i = 0;i < space;i++) {
                printf(" ");
            }
            space--;
            for(int i = 0;i < curr;i++) {
                printf("*");
            }
            printf("\n");
            curr += 2;
        }
    }
}

int main() {
    pyramid(39);
    return 0;
}