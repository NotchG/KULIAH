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
        char key_code;
        int score = 0;
        int lives = 3;
        char map[100][100] = {
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
            {"##                                           ###                                                 ##"},
            {"##                                           ###                                                 ##"},
            {"##                     #########################                                                 ##"},
            {"##                             #################                                                 ##"},
            {"##                                           ##########################                          ##"},
            {"##                                           ###                                                 ##"},
            {"##                                           ###                                                 ##"},
            {"##                                           ###                                                 ##"},
            {"###################################################################################################"},
        };
        while(1 == 1) {
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

            switch (key_code) {
                    case 'w': {
                        if (map[y - 1][x] == '#') {
                            key_code = ' ';
                        }
                        map[y][x] = ' ';
                        y--;
                    }
                    case 'a': {
                        if (map[y][x - 1] == '#') {
                            key_code = ' ';
                        }
                        map[y][x] = ' ';
                        x--;
                    }
                    case 's': {
                        if (map[y + 1][x] == '#') {
                            key_code = ' ';
                        }
                        map[y][x] = ' ';
                        y++;
                    }
                    case 'd': {
                        if (map[y][x + 1] == '#') {
                            key_code = ' ';
                        }
                        map[y][x] = ' ';
                        x++;
                    }
            }

            if (_kbhit()) {
                key_code = _getch();
                printf("Current KeyCode = %c\n", key_code);
                if (key_code == 0) {
                    key_code = getch();
                } else {
                    
                }
                
            } else {
                system("cls");
                continue;
            }
            
            system("cls");
        }
    }
    return 0;
}