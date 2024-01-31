#include <stdio.h>

int main() {
    int range01;
    int range11;
    int value;
    puts("Find Subnet");
    printf("Input starting range: (hostid)");
    scanf("%d.%d", &range01, &range11);
    printf("n Subnet: ");
    scanf("%d", &value);

    for (int i = 0;i < value;i++) {
        if (range11 == -1) {
            range01++;
            range11++;
            continue;
        }
        if (range11 == 255) {
            range11 = -1;
            continue;
        }
        range11++;
    }

    printf("found subnet at: %d.%d", range01, range11);
}