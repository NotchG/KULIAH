#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int matrix[100][100] = {0}; 

  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for (int i = 0; i < N; i++) {
        int rowCheck[101] = {0}; 
        for (int j = 0; j < N; j++) {
            if (rowCheck[matrix[i][j]] == 1) {
                printf("Nay\n");
                return 0;
            }
            rowCheck[matrix[i][j]] = 1;
        }
    }


    for (int j = 0; j < N; j++) {
        int colCheck[101] = {0}; 
        for (int i = 0; i < N; i++) {
            if (colCheck[matrix[i][j]] == 1) {
                printf("Nay\n");
                return 0;
            }
            colCheck[matrix[i][j]] = 1;
        }
    }


    printf("Yay\n");

    return 0;
}