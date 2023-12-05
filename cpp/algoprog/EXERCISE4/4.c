#include <stdio.h>

struct Mhs {
    char name[20];
    int nim;
    float gpa;
};

int main() {
    FILE *fp;
    struct Mhs mahasiswa[10];
    fp = fopen("Mhs.dat", "rb");
    if (fp==NULL){
        printf("Error occurred.\n");
        return 1;
    }
    fread(mahasiswa, sizeof(struct Mhs), 5, fp);
    fclose(fp);
    fp = fopen("Mhs.dat", "wb");
    printf("Enter data:\n");
    for (int i = 4; i < 10; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", mahasiswa[i].name);
        printf("NIM: ");
        scanf("%d", &mahasiswa[i].nim);
        printf("GPA: ");
        scanf("%f", &mahasiswa[i].gpa);
    }
    printf("%-10s %-20s %.3s\n", "NIM", "NAME", "GPA");
    for (int i = 0;i < 10;i++) {
        printf("%-10d %-20s %.3f\n", mahasiswa[i].nim, mahasiswa[i].name, mahasiswa[i].gpa);
    }
    fwrite(mahasiswa, sizeof(struct Mhs) * 10, 1, fp);
    fclose(fp);
    return 0;
}