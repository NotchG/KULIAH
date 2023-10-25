#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int animationFloodFill(char map[19][39]) {
    for(int i = 0;i < 19;i++) {
        for (int j =0;j < 19;j++){
            map[i][j] = 'x';
        }
        system("cls");
            for (int i = 0;i < 19;i++) {
                printf("%s", map[i]);
                if (i == 5) {
                printf("      W  S  A  D  to  move\n");
                continue;
            }
            if (i == 8) {
                printf("      LEGENDS\n");
                continue;
            }
            if (i == 9) {
                printf("      ____________________\n");
                continue;
            }
            if (i == 10) {
                printf("      P player\n");
                continue;
            }
            if (i == 11) {
                printf("      l mummy\n");
                continue;
            }
            if (i == 12) {
                printf("      o escape\n");
                continue;
            }
            if (i == 15) {
                printf("      Press ENTER to exit\n");
                continue;
            }
            printf("\n");
            }
            for (int j =19;j < 38;j++){
            map[i][j] = 'x';
        }
        system("cls");
            for (int i = 0;i < 19;i++) {
                printf("%s", map[i]);
                if (i == 5) {
                printf("      W  S  A  D  to  move\n");
                continue;
            }
            if (i == 8) {
                printf("      LEGENDS\n");
                continue;
            }
            if (i == 9) {
                printf("      ____________________\n");
                continue;
            }
            if (i == 10) {
                printf("      P player\n");
                continue;
            }
            if (i == 11) {
                printf("      l mummy\n");
                continue;
            }
            if (i == 12) {
                printf("      o escape\n");
                continue;
            }
            if (i == 15) {
                printf("      Press ENTER to exit\n");
                continue;
            }
            printf("\n");
            }
    }
    for(int i = 0;i < 19;i++) {
        for (int j =0;j < 19;j++){
            map[i][j] = ' ';
        }
        system("cls");
            for (int i = 0;i < 19;i++) {
                printf("%s\n", map[i]);
            }
            for (int j =19;j < 38;j++){
            map[i][j] = ' ';
        }
        system("cls");
            for (int i = 0;i < 19;i++) {
                printf("%s\n", map[i]);
            }
    }
}

int playGame(int diff) {
    int pPos[2] = {3, 3};
    int numOfMummies = 0;
    int lPos[9][2];
    char maps[3][19][39] = {
        {
        "######################################",
        "#                                    #",
        "#  p        #                        #",
        "#           #   l                    #",
        "#           #                        #",
        "#           # ######                 #",
        "#                                    #",
        "#                                    #",
        "#      # ######                   l  #",
        "#      #                             #",
        "#      #                     ###     #",
        "#      #                     ###     #",
        "#                            ###     #",
        "#  l                                 #",
        "#                ####                #",
        "#                #  #                #",
        "#                ####              o #",
        "#                                    #",
        "######################################"
    },
    {
        "######################################",
        "#                 o                  #",
        "#                ###       #         #",
        "#                   l                #",
        "#                     ####           #",
        "#                                    #",
        "#                #              l    #",
        "#    ##             #                #",
        "#       #                            #",
        "#       # l       # # #              #",
        "#                                    #",
        "#                #                   #",
        "#                #                   #",
        "#                                    #",
        "#        ##                          #",
        "#            #                    ####",
        "#       l  #                 #     p #",
        "#                 #          #       #",
        "######################################",
    },
    {
        "######################################",
        "#                               p    #",
        "#                    #               #",
        "#       #                    ####### #",
        "#                  #                 #",
        "#      # ######   l          ###     #",
        "#      #                     #     l #",
        "#      #           ####              #", 
        "#                          ##        #",
        "#               ### l                #",
        "#     l   ##            #      l     #",
        "#         ##          # #            #",
        "#               #####                #",
        "#    ###                ############ #",
        "#    ###    l     ###         l      #",
        "#    ###              #         #### #",
        "#     l               #       #   o  #",
        "#                    l               #",
        "######################################",
    }
    };
    char map[19][39];
    for (int i = 0;i < 19;i++) {
        strcpy(map[i], maps[diff-1][i]);
    }
    for (int i = 0;i < 19;i++) {
        for (int j = 0;j < 39;j++) {
            char x = map[i][j];
            if (x == 'p') {
                pPos[0] = j;
                pPos[1] = i;
                continue;
            }
            if (x == 'l') {
                lPos[numOfMummies][0] = j;
                lPos[numOfMummies][1] = i;
                numOfMummies++;
            }
        }
    }
    while (1) {
        system("cls");
        map[pPos[1]][pPos[0]] = 'p';
        for (int i = 0;i < 3;i++) {
            map[lPos[i][1]][lPos[i][0]] = 'l';
        }
        for (int i = 0;i < 19;i++) {
            printf("%s", map[i]);
            if (i == 5) {
                printf("      W  S  A  D  to  move\n");
                continue;
            }
            if (i == 8) {
                printf("      LEGENDS\n");
                continue;
            }
            if (i == 9) {
                printf("      ____________________\n");
                continue;
            }
            if (i == 10) {
                printf("      P player\n");
                continue;
            }
            if (i == 11) {
                printf("      l mummy\n");
                continue;
            }
            if (i == 12) {
                printf("      o escape\n");
                continue;
            }
            if (i == 15) {
                printf("      Press ENTER to exit\n");
                continue;
            }
            printf("\n");
        }
        char input = _getch();
        map[pPos[1]][pPos[0]] = ' ';
        if (input == '\r') {
            animationFloodFill(map);
            return 0;
        }
        if (input != 'w' && input != 'a' && input != 's' && input != 'd') {
            continue;
        }
        switch (input) {
            case 'a': {
                char x = map[pPos[1]][pPos[0] - 1];
                if (x == ' ') {
                    pPos[0]--;
                } else if (x == 'l') {
                    animationFloodFill(map);
                    return 0;
                } else if (x == 'o') {
                    animationFloodFill(map);
                    return 1;
                }
                break;
            }
            case 'w': {
                char x = map[pPos[1] - 1][pPos[0]];
                if (x == ' ') {
                    pPos[1]--;
                } else if (x == 'l') {
                    animationFloodFill(map);
                    return 0;
                } else if (x == 'o') {
                    animationFloodFill(map);
                    return 1;
                }
                break;
            }
            case 'd': {
                char x = map[pPos[1]][pPos[0] + 1];
                if (x == ' ') {
                    pPos[0]++;
                } else if (x == 'l') {
                    animationFloodFill(map);
                    return 0;
                } else if (x == 'o') {
                    animationFloodFill(map);
                    return 1;
                }
                break;
            }
            case 's': {
                char x = map[pPos[1] + 1][pPos[0]];
                if (x == ' ') {
                    pPos[1]++;
                } else if (x == 'l') {
                    animationFloodFill(map);
                    return 0;
                } else if (x == 'o') {
                    animationFloodFill(map);
                    return 1;
                }
                break;
            }
        }
        for (int i = 0;i < numOfMummies;i++) {
            map[lPos[i][1]][lPos[i][0]] = ' ';
            if (rand() % 101 <= diff*25) {
                int upOrdown = (lPos[i][1] < pPos[1]) ? 1 : -1;
                int leftOrright = (lPos[i][0] < pPos[0]) ? 1 : -1;
                int tempPosx = lPos[i][0] + leftOrright;
                int tempPosy = lPos[i][1] + upOrdown;
                char x = map[tempPosy][tempPosx];
                if (tempPosx == pPos[0] && tempPosy == pPos[1]) {
                    animationFloodFill(map);
                    return 0;
                } else if (x == ' ') {
                    lPos[i][0] = tempPosx;
                    lPos[i][1] = tempPosy;
                }
            } else {
                int tempPosx = lPos[i][0] + (rand() % 3 - 1);
                int tempPosy = lPos[i][1] + (rand() % 3 - 1);
                char x = map[tempPosy][tempPosx];
                if (tempPosx == pPos[0] && tempPosy == pPos[1]) {
                    animationFloodFill(map);
                    return 0;
                } else if (x == ' ') {
                    lPos[i][0] = tempPosx;
                    lPos[i][1] = tempPosy;
                }
            }
        }
        
    }
}

int main() {

    int diff;

    puts(" _       ____  ____   ____  ____   ____  ____   ______  __ __     ");
    puts("| T     /    T|    \\ l    j|    \\ l    j|    \\ |      T|  T  T    ");
    puts("| |    Y  o  ||  o  ) |  T |  D  ) |  T |  _  Y|      ||  l  |    ");
    puts("| l___ |     ||     T |  | |    /  |  | |  |  |l_j  l_j|  _  |    ");
    puts("|     T|  _  ||  O  | |  | |    \\  |  | |  |  |  |  |  |  |  |    ");
    puts("|     ||  |  ||     | j  l |  .  Y j  l |  |  |  |  |  |  |  |    ");
    puts("l_____jl__j__jl_____j|____jl__j\\_j|____jl__j__j  l__j  l__j__j    ");
    puts("_--___-^_^-_--__^-_--__^-_--____-^_^-_-^_^-_---__^--__-");
    puts("                                                                  ");
    puts("Welcome to labiRInth!\n");
    puts("One day, you wake up in a cursed labyrinth and want to escape.");
    puts("But,you realised that it might not be that easy.");
    puts("As you look around, you realize that there are mummies roaming the place.");
    puts("Try to get to the exit without getting caught by the mummies.");
    puts("Good luck and have fun!\n");
    puts("Press any key to continue...");
    _getch();
    while (1) {
        system("cls");
        puts(" _       ____  ____   ____  ____   ____  ____   ______  __ __     ");
        puts("| T     /    T|    \\ l    j|    \\ l    j|    \\ |      T|  T  T    ");
        puts("| |    Y  o  ||  o  ) |  T |  D  ) |  T |  _  Y|      ||  l  |    ");
        puts("| l___ |     ||     T |  | |    /  |  | |  |  |l_j  l_j|  _  |    ");
        puts("|     T|  _  ||  O  | |  | |    \\  |  | |  |  |  |  |  |  |  |    ");
        puts("|     ||  |  ||     | j  l |  .  Y j  l |  |  |  |  |  |  |  |    ");
        puts("l_____jl__j__jl_____j|____jl__j\\_j|____jl__j__j  l__j  l__j__j    ");
        puts("_--___-^_^-_--__^-_--__^-_--____-^_^-_-^_^-_---__^--__-");
        puts("                                                                  ");
        puts("Difficulty Level");
        puts("____________________");
        puts("1. Easy");
        puts("2. Medium");
        puts("3. Hard");
        printf("Input DIfficulty >> ");
        scanf("%d", &diff);
        if (diff <= 3 && diff > 0) {
            break;
        }
    }
    int game = playGame(diff);
    if (game == 1) {
        system("cls");
        puts(" __      __ __   ___   __ __      __    __  ____  ____       __ ");
        puts("|  |    |  |  | /   \\ |  |  |    |  |__|  ||    ||    \\     |  |");
        puts("|  |    |  |  ||     ||  |  |    |  |  |  | |  | |  _  |    |  ||");
        puts("|__|    |  ~  ||  O  ||  |  |    |  |  |  | |  | |  |  |    |__|");
        puts(" __     |___, ||     ||  :  |    |  `  '  | |  | |  |  |     __ ");
        puts("|  |    |     ||     ||     |     \\      /  |  | |  |  |    |  |");
        puts("|__|    |____/  \\___/  \\__,_|      \\_/\\_/  |____||__|__|    |__|");
        puts("                                                                ");
        puts("Press any key to continue...");
        _getch();
    } else if (game == 0) {
        system("cls");
        puts(" __      __ __   ___   __ __      _       ___   _____ ______      __ ");
        puts("|  |    |  |  | /   \\ |  |  |    | |     /   \\ / ___/|      |    |  |");
        puts("|  |    |  |  ||     ||  |  |    | |    |     (   \\_ |      |    |  |");
        puts("|__|    |  ~  ||  O  ||  |  |    | |___ |  O  |\\__  ||_|  |_|    |__|");
        puts(" __     |___, ||     ||  :  |    |     ||     |/  \\ |  |  |       __ ");
        puts("|  |    |     ||     ||     |    |     ||     |\\    |  |  |      |  |");
        puts("|__|    |____/  \\___/  \\__,_|    |_____| \\___/  \\___|  |__|      |__|");
        puts("                                                                     ");
        puts("Press any key to continue...");
        _getch();
    }
    return 0;
}