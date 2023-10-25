#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char WILD_POKEMON[4][50] = {
    "Charmander",
    "Bulbasaur",
    "Squirtle",
    "SlowPoke"
};

char PLAYER_POKEMON[5][50];
int currPokemonIdx = 0;

int addPokemon(char *pokemon) {
    for (int i = 0;i < currPokemonIdx;i++) {
        if (strcmp(pokemon, PLAYER_POKEMON[i]) == 0) {
            return 0;
        }
    }
    strcpy(PLAYER_POKEMON[currPokemonIdx], pokemon);
    currPokemonIdx++;
    return 1;
}

int main() {
    srand(time(NULL));
    addPokemon("Pikachu");
    while(1) {
        char wildPokemon[100];
        int choice = -1;
        strcpy(wildPokemon, WILD_POKEMON[rand() % 4]);
        printf("A wild %s appeared!\n\n", wildPokemon);
        puts("Choose your Pokemon:");
        for (int i = 0;i < currPokemonIdx;i++) {
            printf("%d. %s\n", i+1, PLAYER_POKEMON[i]);
        }
        while (1) {
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar();
            if (choice - 1 < currPokemonIdx && choice - 1 >= 0) {
                break;
            }
        }
        printf("Go %s!\n", PLAYER_POKEMON[choice - 1]);
        puts("After a long battle...");
        printf("Do you want to catch %s (y/n): ", wildPokemon);
        char catch = getchar();
        getchar();
        if (catch == 'y') {
            int success = addPokemon(wildPokemon);
            if (success == 1) {
                printf("You caught %s!\n", wildPokemon);
            } else {
                printf("You already have %s!\n", wildPokemon);
            }
        }
        printf("Continue (y/n): ");
        char continueGame = getchar();
        getchar();
        if (continueGame != 'y') {
            break;
        }
    }
    return 0;
}