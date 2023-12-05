#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char date[9];
    int above = 0, bet1 = 0, bet2 = 0, bet3 = 0, below = 0;

    file = fopen("employeeDates.txt", "r");

    if (file == NULL) {
        printf("Error occurred.\n");
        return 1;
    }

    while (fscanf(file, "%s", date) != EOF) {
        int currYear = 2023;
        int day, month, year;
        sscanf(date, "%d/%d/%d", &day, &month, &year);

        int age = currYear - (year + 1900);

        if (age > 51) {
            above++;
        } else if (age >= 44 && age <= 51) {
            bet1++;
        } else if (age >= 36 && age <= 43) {
            bet2++;
        } else if (age >= 28 && age <= 35) {
            bet3++;
        } else {
            below++;
        }
    }

    fclose(file);

    printf("Above 51: %d\n", above);
    printf("Between 44-51: %d\n", bet1);
    printf("Between 36-43: %d\n", bet2);
    printf("Between 28-35: %d\n", bet3);
    printf("Below 28: %d\n", below);

    return 0;
}