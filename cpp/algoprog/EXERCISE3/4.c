#include <stdio.h>

struct ipkmhs {
    char nim[11];
    char nama[30];
    float gpa;
};

int main() {
    struct ipkmhs mahasiswa[5];
    for (int i = 0;i < 5;i++) {
        printf("Input Data %d: [nim, name, gpa] please enter for each answer\n", i+1);
        scanf("%s", mahasiswa[i].nim);
        getchar();
        scanf("%[^\n]", mahasiswa[i].nama);
        getchar();
        scanf("%f", &mahasiswa[i].gpa);
        getchar();
    }
    puts("-------- Mahasiswa GPA >= 3.0 ---------");
    for (int i = 0;i < 5;i++) {
        
        if (mahasiswa[i].gpa >= 3) {
            printf("%s\n", mahasiswa[i].nama);
        }
    }
    puts("-------- Mahasiswa GPA < 3.0 ---------");
    for (int i = 0;i < 5;i++) {
        
        if (mahasiswa[i].gpa < 3) {
            printf("%s\n", mahasiswa[i].nama);
        }
    }
    return 0;
}