#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node* prev;
    char data[100];
    struct node* next;
};

struct node* addNode(struct node* head, char data[100]) {
    struct node* temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    strcpy(temp->data, data);
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL) {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}

struct node* addNodeEmpty(struct node* head, char data[100]) { 
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    strcpy(temp->data, data);
    temp->next = NULL;
    head = temp;
    return head;
}

int main() {

    char arr[3][100] = {
        "Hello",
        "World",
        "HERLF"
    };

    struct node* head = NULL;
    struct node* ptr;
    
    for (int i = 0;i < 3;i++) {
        if (head == NULL) {
            head = addNodeEmpty(head, arr[i]);
        } else {
            head = addNode(head, arr[i]);
        }
    }
    ptr = head;
    while (ptr != NULL) {
        printf("%s\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}