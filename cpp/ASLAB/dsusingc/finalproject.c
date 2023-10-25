#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

void exitGame() {
    
}

void playGame4() {
    int score = 0;
    int block[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    while (1) {
        int *randBlock = &block[rand() % 4][rand() % 4];
        if (*randBlock == 0) {
            if (rand() % 101 <= (score >= 1000 ? 30 : 70)) {
                *randBlock = 2;
            } else {
                *randBlock = 4;
            }
        }
        int block_i = -1;
        int block_j = -1;
        system("cls");
        int skip = 0;
        for (int i = 0;i < 17;i++) {
            if (i % 4 == 0) {
                block_i++;
            }
            for (int j = 0;j < 25;j++) {
                if (i % 4 == 0) {
                    printf("\e[0;30m");
                    printf("\xDB");
                    continue;
                }
                if (j % 6 == 0) {
                    printf("\e[0;30m");
                    printf("\xDB");
                    if (block_j == 4) {
                        block_j = 0;
                    } else {
                        block_j++;
                    }
                    continue;
                }
                if (skip != 0) {
                    skip--;
                    continue;
                }
                if(block[block_i][block_j] != 0) {
                    if (j % 3 == 0 && i % 2 == 0) {
                        printf("%d", block[block_i][block_j]);
                        if (block[block_i][block_j] >= 100) {
                            skip = 2;
                        } else if (block[block_i][block_j] >= 10) {
                            skip = 1;
                        }
                        continue;
                    }
                }
                if (block[block_i][block_j] == 2) {
                    printf("\e[0;31m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] == 4) {
                    printf("\e[0;32m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] == 8) {
                    printf("\e[0;33m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] == 16) {
                    printf("\e[0;34m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] == 32) {
                    printf("\e[0;35m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] > 32) {
                        printf("\e[0;36m");
                        printf("\xDB");
                        continue;
                }
                printf("\e[0;37m");
                printf("\xDB");
            }
            printf("\033[0m");
            if (i == 5) {
                printf("        Score: %d", score);
            }
            if (i == 7) {
                printf("        [Press q to exit]");
            }
            printf("\n");
        }
        char input = _getch();
        switch (toupper(input)) {
            case 'D': {
                for (int i = 0;i < 4;i++) {
                    for (int j = 0;j < 3;j++) {
                        if (block[i][j] == 0) {
                            continue;
                        }
                        if (j+1 == 4) {
                            break;
                        }
                        if (block[i][j+1] == 0) {
                            block[i][j+1] = block[i][j];
                            block[i][j] = 0;
                            continue;
                        } else if (block[i][j] == block[i][j+1]) {
                            block[i][j+1] = block[i][j] << 1;
                            score += block[i][j+1];
                            block[i][j] = 0;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'A': {
                for (int i = 0;i < 4;i++) {
                    for (int j = 3;j >= 0;j--) {
                        if (block[i][j] == 0) {
                            continue;
                        }
                        if (j-1 < 0) {
                            break;
                        }
                        if (block[i][j-1] == 0) {
                            block[i][j-1] = block[i][j];
                            block[i][j] = 0;
                            continue;
                        } else if (block[i][j] == block[i][j-1]) {
                            block[i][j-1] = block[i][j] << 1;
                            score += block[i][j-1];
                            block[i][j] = 0;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'W': {
                for (int i = 0;i < 4;i++) {
                    for (int j = 3;j >= 0;j--) {
                        if (block[i][j] == 0) {
                            continue;
                        }
                        if (i-1 < 0) {
                            break;
                        }
                        if (block[i-1][j] == 0) {
                            block[i-1][j] = block[i][j];
                            block[i][j] = 0;
                            continue;
                        } else if (block[i][j] == block[i-1][j]) {
                            block[i-1][j] = block[i][j] << 1;
                            score += block[i-1][j];
                            block[i][j] = 0;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'S': {
                for (int i = 0;i < 4;i++) {
                    for (int j = 0;j < 3;j++) {
                        if (block[i][j] == 0) {
                            continue;
                        }
                        if (i+1 == 4) {
                            break;
                        }
                        if (block[i+1][j] == 0) {
                            block[i+1][j] = block[i][j];
                            block[i][j] = 0;
                            continue;
                        } else if (block[i][j] == block[i+1][j]) {
                            block[i+1][j] = block[i][j] << 1;
                            score += block[i+1][j];
                            block[i][j] = 0;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'Q': {
                return;
                break;
            }
        }

    }
}

void playGame6() {
    int score = 0;
    int block[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
    };
    while (1) {
        int *randBlock = &block[rand() % 6][rand() % 6];
        if (*randBlock == 0) {
            if (rand() % 101 <= (score >= 1000 ? 30 : 70)) {
                *randBlock = 2;
            } else {
                *randBlock = 4;
            }
            
        }
        int block_i = -1;
        int block_j = -1;
        system("cls");
        int skip = 0;
        for (int i = 0;i < 25;i++) {
            if (i % 4 == 0) {
                block_i++;
            }
            for (int j = 0;j < 37;j++) {
                if (i % 4 == 0) {
                    printf("\e[0;30m");
                    printf("\xDB");
                    continue;
                }
                if (j % 6 == 0) {
                    printf("\e[0;30m");
                    printf("\xDB");
                    if (block_j == 6) {
                        block_j = 0;
                    } else {
                        block_j++;
                    }
                    continue;
                }
                if (skip != 0) {
                    skip--;
                    continue;
                }
                if(block[block_i][block_j] != 0) {
                    if (j % 3 == 0 && i % 2 == 0) {
                        printf("%d", block[block_i][block_j]);
                        if (block[block_i][block_j] >= 100) {
                            skip = 2;
                        } else if (block[block_i][block_j] >= 10) {
                            skip = 1;
                        }
                        continue;
                    }
                }
                if (block[block_i][block_j] == 2) {
                    printf("\e[0;31m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] == 4) {
                    printf("\e[0;32m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] == 8) {
                    printf("\e[0;33m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] == 16) {
                    printf("\e[0;34m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] == 32) {
                    printf("\e[0;35m");
                    printf("\xDB");
                    continue;
                }
                if (block[block_i][block_j] > 32) {
                        printf("\e[0;36m");
                        printf("\xDB");
                        continue;
                }
                printf("\e[0;37m");
                printf("\xDB");
            }
            printf("\033[0m");
            if (i == 5) {
                printf("        Score: %d", score);
            }
            if (i == 7) {
                printf("        [Press q to exit]");
            }
            printf("\n");
        }
        char input = _getch();
        switch (toupper(input)) {
            case 'D': {
                for (int i = 0;i < 6;i++) {
                    for (int j = 0;j < 5;j++) {
                        if (block[i][j] == 0) {
                            continue;
                        }
                        if (j+1 == 4) {
                            break;
                        }
                        if (block[i][j+1] == 0) {
                            block[i][j+1] = block[i][j];
                            block[i][j] = 0;
                            continue;
                        } else if (block[i][j] == block[i][j+1]) {
                            block[i][j+1] = block[i][j] << 1;
                            score += block[i][j+1];
                            block[i][j] = 0;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'A': {
                for (int i = 0;i < 6;i++) {
                    for (int j = 5;j >= 0;j--) {
                        if (block[i][j] == 0) {
                            continue;
                        }
                        if (j-1 < 0) {
                            break;
                        }
                        if (block[i][j-1] == 0) {
                            block[i][j-1] = block[i][j];
                            block[i][j] = 0;
                            continue;
                        } else if (block[i][j] == block[i][j-1]) {
                            block[i][j-1] = block[i][j] << 1;
                            score += block[i][j-1];
                            block[i][j] = 0;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'W': {
                for (int i = 0;i < 6;i++) {
                    for (int j = 5;j >= 0;j--) {
                        if (block[i][j] == 0) {
                            continue;
                        }
                        if (i-1 < 0) {
                            break;
                        }
                        if (block[i-1][j] == 0) {
                            block[i-1][j] = block[i][j];
                            block[i][j] = 0;
                            continue;
                        } else if (block[i][j] == block[i-1][j]) {
                            block[i-1][j] = block[i][j] << 1;
                            score += block[i-1][j];
                            block[i][j] = 0;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'S': {
                for (int i = 0;i < 6;i++) {
                    for (int j = 0;j < 5;j++) {
                        if (block[i][j] == 0) {
                            continue;
                        }
                        if (i+1 == 4) {
                            break;
                        }
                        if (block[i+1][j] == 0) {
                            block[i+1][j] = block[i][j];
                            block[i][j] = 0;
                            continue;
                        } else if (block[i][j] == block[i+1][j]) {
                            block[i+1][j] = block[i][j] << 1;
                            score += block[i+1][j];
                            block[i][j] = 0;
                            continue;
                        }
                    }
                }
                break;
            }
            case 'Q': {
                return;
                break;
            }
        }
    }
}

void inputGame() {
    int gridSize;
    while (1){
        printf("Input Grid Size [4 or 6]: ");
        scanf("%d", &gridSize);
        if (gridSize == 4) {
            playGame4();
            break;
        } else if (gridSize == 6) {
            playGame6();
            break;
        }
    };
}

int main() {
    srand(time(NULL));
    int opt;
    while (1){
        system("cls");
        puts("  ______             __                     ");
        puts(" /      \\           /  |                    ");
        puts("/$$$$$$  |  ______  $$ | __    __  __    __ ");
        puts("$$ |  $$/  /      \\ $$ |/  |  /  |/  \\  /  |");
        puts("$$ |       $$$$$$  |$$ |$$ |  $$ |$$  \\/$$/ ");
        puts("$$ |   __  /    $$ |$$ |$$ |  $$ | $$  $$<  ");
        puts("$$ \\__/  |/$$$$$$$ |$$ |$$ \\__$$ | /$$$$  \\ ");
        puts("$$    $$/ $$    $$ |$$ |$$    $$ |/$$/ $$  |");
        puts(" $$$$$$/   $$$$$$$/ $$/  $$$$$$$ |$$/   $$/ ");
        puts("                        /  \\__$$ |          ");
        puts("                        $$    $$/           ");
        puts("                         $$$$$$/            ");
        puts("1. New Game");
        puts("2. Highscore");
        puts("3. Exit");
        printf(">> ");
        scanf("%d", &opt);
        getchar();
        if (opt == 1) {
            inputGame();
        }
        if (opt == 2) {

        }
        if (opt == 3) {
            return 0;
        }
    };
    return 0;
}