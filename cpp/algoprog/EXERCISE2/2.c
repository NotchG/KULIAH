#include <stdio.h>

void move(int disk, int source, int dest) {
    printf("Moving disk #%d from %s to %s\n", disk, source == 3 ? "right" : source == 2 ? "middle" : "left", dest == 3 ? "right" : dest == 2 ? "middle" : "left");
}

void hanoi(int n, int left, int middle, int right) {
    if (n == 1) {
        move(n, left, right);
        return;
    }

    hanoi(n-1, left, right, middle);

    move(n, left, right);
    
    hanoi(n-1, middle, left, right);
}

int main() {
    hanoi(4, 1, 2, 3);
    return 0;
}