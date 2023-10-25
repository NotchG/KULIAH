#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

// insert if list is empty
// insert if list is not empty

struct Node* createNode(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node*));
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        return head;
    } else {
        struct Node *temp; // The new node that we want to add
        struct Node *prevHead; // reference to the previous head
        temp = malloc(sizeof(struct Node*));
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        prevHead = head;
        while (prevHead->next != NULL) {
            prevHead = prevHead->next;
        }
        prevHead->next = temp;
        temp->prev = prevHead;
        return head;
    }
}

int main() {

    int arr[5] = {1, 5, 2, 7, 8};
    struct Node *head = NULL;

    for (int i = 0;i < 5;i++) {
        head = createNode(head, arr[i]);
    }

    
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}