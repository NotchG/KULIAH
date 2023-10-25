#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    printf(" _    __ __      _   _   _\n");
    printf("| |  \\    /    | \\   _   _\n");
    printf("| |__ )   (     | _   _\n");
    printf("|____/__n__\\   | _   _   _   _   _\n");

    printf("1. Play\n2.Exit\nEnter your choice: ");
    char play = getchar();
    if (play == '1') {
        int x = 50;
        int y = 10;
        int score = 0;
        int lives = 3;
        char map[20][100] = {
            {"###################################################################################################"},
            {"##                                           ###                                                 ##"},
            {"##               ##########                  ###                                                 ##"},
            {"##        ##################                 ###                 #####################           ##"},
            {"##        ##################                 ###                     ###############             ##"},
            {"##            ########                       ###                             #####               ##"},
            {"##                                           ###                                                 ##"},
            {"##                                           ###                                                 ##"},
            {"##                                                                                               ##"},
            {"##                                                                                               ##"},
            {"##                                                                                               ##"},
            {"##                                                                                               ##"},
            {"##                                                                                               ##"},
            {"##                     ######################                                                    ##"},
            {"##                             #################                                                 ##"},
            {"##                                           ##########################                          ##"},
            {"##                                           ###                                                 ##"},
            {"##                                           ###                                                 ##"},
            {"##                                           ###                                                 ##"},
            {"###################################################################################################"},
        };
        while(1 == 1) {
            system("cls");
            map[y][x] = 'X';
            printf(" _    __ __      _   _   _\n");
            printf("| |  \\    /    | \\   _   _\n");
            printf("| |__ )   (     | _   _\n");
            printf("|____/__n__\\   | _   _   _   _   _\n");
            for (int i = 0;i < 20;i++) {
                printf("%s\n", map[i]);
            }
            printf("Score = %d\n", score);
            printf("Life = %d\n", lives);

            if (_kbhit()) {
                char key_code = _getch();
                printf("Current KeyCode = %c\n", key_code);
                switch (key_code) {
                    case 'w': {
                        if (map[y - 1][x] == '#') continue;
                        map[y][x] = ' ';
                        y--;
                    }
                    case 'a': {
                        if (map[y][x - 1] == '#') continue;
                        map[y][x] = ' ';
                        x--;
                    }
                    case 's': {
                        if (map[y + 1][x] == '#') continue;
                        map[y][x] = ' ';
                        y++;
                    }
                    case 'd': {
                        if (map[y][x + 1] == '#') continue;
                        map[y][x] = ' ';
                        x++;
                    }
                }
            } else {
                continue;
            }
        }
    }
    return 0;
}