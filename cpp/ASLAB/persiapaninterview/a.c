#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node * createNode(struct Node *head, int data) {
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

struct Node * createNodeAtBeginning(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->prev = NULL;
        head->next = NULL;
        head->data = data;
        return head;
    } else {
        struct Node *temp;
        temp = malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = data;
        head->prev = temp;
        temp->next = head;
        return temp;
    }
}

struct Node * createAscSortNode(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->prev = NULL;
        head->next = NULL;
        head->data = data;
    } else {
        if (head->data > data) {
            head = createNodeAtBeginning(head, data);
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
        if (curr->next == NULL) {
            curr->next = temp;
            temp->prev = curr;
            return head;
        }
        curr->prev->next = temp;
        temp->prev = curr->prev;
        curr->prev = temp;
        temp->next = curr;
    }
    return head;
}

struct Node * createDscSortNode(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->prev = NULL;
        head->next = NULL;
        head->data = data;
    } else {
        if (head->data < data) {
            head = createNodeAtBeginning(head, data);
            return head;
        }
        struct Node *temp, *curr;
        temp = malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = data;
        curr = head;
        while (curr->next != NULL && curr->data > data) {
            curr = curr->next;
        }
        if (curr->next == NULL) {
            curr->next = temp;
            temp->prev = curr;
            return head;
        }
        curr->prev->next = temp;
        temp->prev = curr->prev;
        curr->prev = temp;
        temp->next = curr;
    }
    return head;
}


int main() {
    struct Node *head = NULL;
    int arr[10] = {1, 2, 67, 4, 23, 6, 12, 8, 9, 10};
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