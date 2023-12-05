#include <stdio.h>

struct studentScore {
    char nim[11];
    char name[30];
    char subjectCode[5];
    int sks;
    char grade;
};

int main() {
    struct studentScore student;
    printf("Input Data: [nim, name, subject code, sks, grade] please enter for each answer\n");
    scanf("%s", student.nim);
    getchar();
    scanf("%[^\n]", student.name);
    getchar();
    scanf("%s", student.subjectCode);
    getchar();
    scanf("%d", &student.sks);
    getchar();
    student.grade = getchar();

    printf("NIM: %s\n", student.nim);
    printf("Name: %s\n", student.name);
    printf("Subject Code: %s\n", student.subjectCode);
    printf("SKS: %d\n", student.sks);
    printf("Grade: %c\n", student.grade);
    return 0;
}