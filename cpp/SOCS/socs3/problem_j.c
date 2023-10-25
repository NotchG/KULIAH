#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n",((b-c)==(c-a) && (c-a)>=0 && (b-c)>=0)?b-c:-1);
    return 0;
}