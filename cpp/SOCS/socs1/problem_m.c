#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int octal = 0;
    int i = 0;
    while (n != 0) {
        octal += (n % 8) * pow(10, i);
        n = n/8;
        i++;
    }
    printf("%d\n", octal);
    return 0;
}