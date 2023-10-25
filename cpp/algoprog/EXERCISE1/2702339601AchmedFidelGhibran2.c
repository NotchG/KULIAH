#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Pegawai {
    char nama[100];
    int umur;
    char jabatan[100];
    long int gaji;
    struct Pegawai *next;
}; 

struct Pegawai * createPegawai(struct Pegawai *head, struct Pegawai data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Pegawai));
        head->gaji = data.gaji;
        head->umur = data.umur;
        strcpy(head->nama, data.nama);
        strcpy(head->jabatan, data.jabatan);
        head->next = NULL;
    } else {
        struct Pegawai *temp;
        temp = malloc(sizeof(struct Pegawai));
        temp->gaji = data.gaji;
        temp->umur = data.umur;
        strcpy(temp->nama, data.nama);
        strcpy(temp->jabatan, data.jabatan);
        temp->next = NULL;

        struct Pegawai *curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = temp;
    }
}

int main() {
    struct Pegawai *head = NULL;
    int jumlahPegawai = 1;
    while (1) {
        struct Pegawai pegawai;
        printf("Masukkan pegawai ke-%d:\n", jumlahPegawai++);
        printf("Nama: ");
        scanf("%[^\n]", pegawai.nama);
        getchar();
        printf("Usia: ");
        scanf("%d", &pegawai.umur);
        getchar();
        printf("Jabatan: ");
        scanf("%[^\n]", pegawai.jabatan);
        getchar();
        printf("Gaji: ");
        scanf("%ld", &pegawai.gaji);
        printf("Tambahkan data pegawai lagi? (y/n)");
        head = createPegawai(head, pegawai);
        getchar();
        char choice = getchar();
        getchar();
        if (choice != 'y') {
            break;
        }
    }
    struct Pegawai *curr = head;
    long int ratarata;
    struct Pegawai *gajiTertinggi = head;
    puts("Data pegawai: ");
    printf("%-20s %-5s %-10s %-10s\n", "Nama", "Umur", "Jabatan", "Gaji");
    while (curr != NULL) {
        ratarata += curr->umur;
        printf("%-20s %-5d %-10s %-10d\n", curr->nama, curr->umur, curr->jabatan, curr->gaji);
        if (curr->next != NULL) {
            if (curr->gaji > curr->next->gaji) {
                gajiTertinggi = curr;
            }
        }
        curr = curr->next;
    }
    printf("\nRata-rata usia pegawai: %lf\n", (double) ratarata / (jumlahPegawai - 1));
    printf("Nama: %s\n", gajiTertinggi->nama);
    printf("Usia: %d\n", gajiTertinggi->umur);
    printf("Jabatan: %s\n", gajiTertinggi->jabatan);
    printf("Gaji: %ld\n", gajiTertinggi->gaji);
}