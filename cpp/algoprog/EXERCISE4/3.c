#include <stdio.h>

struct Mhs {
    char name[20];
    int nim;
    float gpa;
};

int main() {
    FILE *fp;
    struct Mhs mahasiswa[5];
    fp = fopen("Mhs.dat", "rb");
    if (fp==NULL){
        printf("Error occurred.\n");
        return 1;
    }
    fread(mahasiswa, sizeof(struct Mhs),5, fp);
    printf("%-10s %-20s %.3s\n", "NIM", "NAME", "GPA");
    for (int i = 0;i < 5;i++) {
        printf("%-10d %-20s %.3f\n", mahasiswa[i].nim, mahasiswa[i].name, mahasiswa[i].gpa);
    }
    return 0;
}