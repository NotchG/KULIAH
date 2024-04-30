// Double Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Node:
prev: pointer ke sebelumnya
data: int
next: pointer ke setelahnya
*/

// malloc

// wildcard : sesuatu diluar prediksi

typedef struct Music {
    char title[100];
    char artist[100];
    int duration;
} Music;

typedef struct Node {
    struct Node *prev;
    struct Music data;
    struct Node *next;
} Node;

Node * createHead(Node *head, Music data) {
    head = malloc(sizeof(Node));
    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    return head;
}

Node * createNodeAtEnd(Node *head, Music data) {
    if (head == NULL) {
        return createHead(head, data);
    } else {
        Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        Node *newNode = NULL;
        newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = curr;
        curr->next = newNode;
        newNode->next = NULL;

        return head;
    }
}

void printAll(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%s - %s - %d:%d\n\n", curr->data.title, curr->data.artist, curr->data.duration / 60, curr->data.duration % 60);
        curr = curr->next;
    }
}

Music createMusic(char *title, char *artist, int duration) {

}

int main() {

    Node *head = NULL;

    // Scan for user input
    for (int i = 0;i < 5;i++){
        system("cls");
        Music music;
        puts("Spotify GB Music Input");
        printf("Title: ");
        scanf("%[^\n]", &music.title);
        getchar();
        printf("Artist: ");
        scanf("%[^\n]", &music.artist);
        getchar();
        printf("Duration: ");
        scanf("%d", &music.duration);
        getchar();
        head = createNodeAtEnd(head, music);
    }
    

    printAll(head);



    return 0;
}