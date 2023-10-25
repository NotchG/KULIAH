#include <stdio.h>

int main() {
    int s, n;
    int win = 1;
    scanf("%d %d", &s, &n);
    char path[n];
    int stamina = n;
    scanf("%s", path);
    for (int i = -1;i < n;i++) {
        if (i != -1) {
            int x = path[i];
            if (stamina - x <= 0 && path[i] != 'X') {
                win = 0;
                break;
            } else if (path[i] == 'X') {
                stamina = n;
            }
        }
        if (path[i + 1] == 'X') {
            continue;
        } else if (path[i + 2] == 'X') {
            i += 2;
            continue;
        }

        if (path[i + 1] > path[i + 2]) {
            continue;
        } else {
            i += 2;
            continue;
        }
    }

    printf("%s\n", win == 0 ? "Gagal" : "Berhasil");
    
    return 0;
}