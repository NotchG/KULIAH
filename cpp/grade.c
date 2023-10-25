#include <stdio.h>

int main() {
    double total = 0;
    int grade_counter = 1;

    while(grade_counter <= 10) {
        int grade;
        printf("Input grade: ");
        scanf("%d", &grade);
        total = total + grade;
        grade_counter++;
    }
    total = total / 10;
    printf("Class Average: %lf", total);
    return 0;
}