#include <stdio.h>
#include <stdlib.h>

struct Mhs {
    char name[20];
    int nim;
    float gpa;
};

int main() {
    FILE *file;
    struct Mhs students[5];

    file = fopen("Mhs.dat", "ab");

    if (file == NULL) {
        printf("Error occurred.\n");
        return 1;
    }

    printf("Enter data:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("NIM: ");
        scanf("%d", &students[i].nim);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    fwrite(students, sizeof(struct Mhs), 5, file);
    fclose(file);

    printf("Data has been written to Mhs.dat\n");

    return 0;
}