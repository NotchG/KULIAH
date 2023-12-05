#include <stdio.h>
#include <ctype.h>

struct studentScore {
    char nim[11];
    char name[30];
    char subjectCode[5];
    int sks;
    char grade;
};

int main() {
    struct studentScore student[5];
    for (int i = 0;i < 5;i++) {
        printf("Input Data: [nim, name, subject code, sks, grade] please enter for each answer\n");
        scanf("%s", student[i].nim);
        getchar();
        scanf("%[^\n]", student[i].name);
        getchar();
        scanf("%s", student[i].subjectCode);
        getchar();
        scanf("%d", &student[i].sks);
        getchar();
        student[i].grade = getchar();
        getchar();
    }

    float average = 0;

    for (int i = 0;i < 5;i++) {
        switch(toupper(student[i].grade)) {
            case 'A': average += 4; break;
            case 'B': average += 3; break;
            case 'C': average += 2; break;
            case 'D': average += 1; break;
        }
    }
    average /= 5;

    printf("%f", average);
    return 0;
}