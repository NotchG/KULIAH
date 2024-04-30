#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node * createNode(int data){
    struct Node * newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode; 
}

struct Node * createNodeatend(struct Node * head, int data){
    if(head == NULL){ 
        head = createNode(data);
        return head;
    } else{
        struct Node * curr = head;
        while(curr->next != NULL){
            curr=curr->next;
        }
        struct Node * newNode = createNode(data);
        curr->next =  newNode;
        newNode->prev = curr;
        return head;

    }
} 
 
 void printAll(struct Node * head){
    struct Node * curr = head;
        while(curr != NULL){
            printf("%d->", curr->data);
            curr=curr->next;
        }
 }



int main(){

struct Node *head =NULL;
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

for(int i=0; i<10; i++){
    head=createNodeatend(head, arr[i]);

}

printAll(head);
    return 0;
}