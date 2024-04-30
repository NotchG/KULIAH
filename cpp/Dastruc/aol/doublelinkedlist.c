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

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node * createHead(Node *head, int data) {
    head = malloc(sizeof(Node));
    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    return head;
}

Node * createNodeAtEnd(Node *head, int data) {
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
        printf("%d->", curr->data);
        curr = curr->next;
    }
}

int main() {

    Node *head = NULL;
    
    int arr[10] = {1,3,5,3,5,6,7,8,9,10};

    for (int i = 0;i < 10;i++) {
        head = createNodeAtEnd(head, arr[i]);
    }

    printAll(head);



    return 0;
}