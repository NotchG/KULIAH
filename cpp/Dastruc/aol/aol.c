#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CHARSIZE 26

typedef struct TrieNode {
    char data; // Stored for printing purposes
    struct TrieNode* chars[CHARSIZE]; // Children of current trienode (stores a-z alphabet)
    bool isLeaf; // boolean to check if it's the end of word or not
    char description[255]; // Variable to store description
} TrieNode;

TrieNode *heads[CHARSIZE] = {NULL};

// Create a new trienode
void createTrieNode(char* word, char* description) {
    TrieNode *curr = NULL;

    // Iterate each letter in the word
    for (int i = 0;i < strlen(word);i++) {
        int currChar = word[i] - 97;

        // Creating a new trienode with the given letter
        TrieNode *node = malloc(sizeof(TrieNode));
        for (int i = 0;i < CHARSIZE;i++) {
            node->chars[i] = NULL;
        }
        node->data = word[i];
        node->isLeaf = false;

        // Check if The first letter have a head
        if (heads[currChar] == NULL) {
            heads[currChar] = node;
            curr = heads[currChar];
        } else {
            // Check if letter in current node exists
            if (curr->chars[currChar] == NULL) {
                curr->chars[currChar] = node;
                printf("%c -> ", curr->chars[currChar]->data);
            } 
            curr = curr->chars[currChar];
        }
    }
    // Set last letter node as a word and add description
    curr->isLeaf = true;
    strcpy(curr->description, description);
    printf("last letter: %c", curr->data);
}

// this function returns an integer: the amount of words a string has
int amountOfWordsValidator(char *string) {
    char *token = strtok(string, " ");
    int words = 0;
    while (token != NULL) {
        words++;
        token = strtok(NULL, " ");
    }
    return words;
}

// releaseNewSlang 
void releaseNewSlang() {
    char word[255];
    char description[255];
    while (true) {
        char temp[255];
        printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
        scanf("%[^\n]", temp);
        getchar();
        if (amountOfWordsValidator(temp) > 1 || strlen(temp) < 2) {
            continue;
        }
        strcpy(word, temp);
        break;
    }
    while (true) {
        char temp[255];
        printf("Input a new slang word description [Must be more than 2 words]: ");
        scanf("%[^\n]", temp);
        getchar();
        if (amountOfWordsValidator(temp) < 2) {
            continue;
        }
        strcpy(description, temp);
        break;
    }
    createTrieNode(word, description);

    printf("\nSuccessfully released new slang word.\nPress enter to continue...");
    getchar();
}

void searchSlangWord() {
    char word[255];
    while (true) {
        char temp[255];
        printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
        scanf("%[^\n]", temp);
        getchar();
        if (amountOfWordsValidator(temp) > 1 || strlen(temp) < 2) {
            continue;
        }
        strcpy(word, temp);
        break;
    }
    TrieNode *curr = heads[word[0] - 97];
    for (int i = 1;i < strlen(word);i++) {
        if (curr == NULL) {
            printf("There is no word \"%s\" in the dictionary.", word);
            break;
        }

        int currChar = word[i] - 97;

        printf("%c ->", word[i]);
        curr = curr->chars[currChar];
    }
    if (curr->isLeaf == true) {
        printf("Slang Word  : %s\n", word);
        printf("Description : %s\n", curr->description);
    }
    printf("Press enter to continue...");
    getchar();
}

void viewAllSlangWordsWithPrefix() {
    char prefix[255];
    while (true) {
        char temp[255];
        printf("Input a prefix to be searched: ");
        scanf("%[^\n]", temp);
        getchar();
        if (amountOfWordsValidator(temp) > 1) {
            continue;
        }
        strcpy(prefix, temp);
        break;
    }

    for (int i = 0;i < strlen(prefix);i++) {
        
    }
}

// mainMenu serves as a Main Menu to display to the user and returns a value to main function
int mainMenu() {
    while (true) {
        // Clears the console
        system("cls");

        // Prints choices to the console
        puts("1. Release a new slang word");
        puts("2. Search a slang word");
        puts("3. View all slang words starting with a certain prefix word");
        puts("4. View all slang words");
        puts("5. Exit");
        printf("Input Choice: ");

        // Wait for user input
        int choice;
        scanf("%d", &choice);
        getchar();

        // Possible choices for user input
        switch (choice) {
            case 1: releaseNewSlang(); break;
            case 2: searchSlangWord(); break;
            case 3: viewAllSlangWordsWithPrefix(); break;
            case 5: return 0;
            default: printf("No Command Found");
        }
    }
}

int main() {
    // Returns 0 / 1 on mainMenu function
    return mainMenu();
}