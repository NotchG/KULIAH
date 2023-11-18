#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node * createNodeAtEnd(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->prev = NULL;
        head->next = NULL;
        head->data = data;
    } else {
        struct Node *temp, *curr;
        temp = malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = data;
        curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
    return head;
}

struct Node * createNodeAtBeg(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->prev = NULL;
        head->next = NULL;
        head->data = data;
    } else {
        struct Node *temp, *curr;
        temp = malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = data;
        head->prev = temp;
        temp->next = head;
        return temp;
    }
    return head;
}

struct Node * createAscSortNode(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->prev = NULL;
        head->next = NULL;
        head->data = data;
    } else {
        if (head->data > data) {
            head = createNodeAtBeg(head, data);
            return head;
        }
        struct Node *temp, *curr;
        temp = malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = data;
        curr = head;
        while (curr->next != NULL && curr->data < data) {
            curr = curr->next;
        }
        if (curr->data > data) {
            curr = curr->prev;
        }
        if (curr->next == NULL) {
            curr->next = temp;
            temp->prev = curr;
        } else {
            curr->next->prev = temp;
            temp->next = curr->next;
            curr->next = temp;
            temp->prev = curr;
        }
    }
    return head;
}

int main() {
    struct Node *head = NULL;
    int arr[10] = {1, 2, 67, 5, 23, 6, 12, 8, 9, 10};
    for (int i = 0;i < 10;i++) {
        head = createAscSortNode(head, arr[i]);
    }
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    return 0;
}