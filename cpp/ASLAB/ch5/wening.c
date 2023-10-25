#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node* insertAtBeg(struct Node *head, int data) {
    struct Node *nextNode = NULL;
    nextNode = malloc(sizeof(struct Node));
    nextNode->data = data;
    nextNode->prev = NULL;
    nextNode->next = NULL;

    head->prev = nextNode;
    nextNode->next = head;
    return nextNode;
}

struct Node* createNode(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        return head;
    } else {
        struct Node *lastNode = head;
        struct Node *nextNode = NULL;
        nextNode = malloc(sizeof(struct Node));
        nextNode->data = data;
        nextNode->prev = NULL;
        nextNode->next = NULL;

        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = nextNode;
        nextNode->prev = lastNode;
        return head;
    }
}


int main() {
    struct Node *head = NULL;
    
    head = createNode(head, 20); 
    head = createNode(head, 30);
    head = createNode(head, 40);
    head = createNode(head, 50);
    head = createNode(head, 60);
    head = createNode(head, 70);
    head = insertAtBeg(head, 80);

    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    return 0;
}