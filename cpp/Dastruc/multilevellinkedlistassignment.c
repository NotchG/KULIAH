#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

MULTI LEVEL LINKED LIST : ASSIGNMENT

You are tasked with implementing a data structure to represent the organizational hierarchy of a
company. Each employee is represented by a node in a multi-level linked list, with each node having a
name and pointers to its direct subordinates and the next employee at the same level

Members:
ACHMED FIDEL GHIBRAN. BN - 2702339601
AZHAR ALZAKI ROSANTO - 2702338132
KERRY FENDY - 2702291835

*/


/*

Node Struct

The Node structure has two pointers and one data:
next: Points to the next employee at the same level (i.e., the next employee reporting to the same
manager).
subordinate: Points to a linked list of subordinates (i.e., employees reporting directly to the current
employee).
name: 100 character string indicating the name of node

*/
typedef struct Node {
    char name[100];
    struct Node *next;
    struct Node *subordinate;
} Node;


// createNode function creates a new node with the given name.
Node * createNode(char *name) {
    // Create Temporary Node
    Node *temp = malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->next = NULL;
    temp->subordinate = NULL;

    // Returns created node
    return temp;
}

// addSubordinate function adds a subordinate node to a given manager
void addSubordinate(Node *head, char *name) {
    // Check if head already contains subordinates
    if (head->subordinate == NULL) {
        // Create Temporary Node
        Node *temp = malloc(sizeof(Node));
        strcpy(temp->name, name);
        temp->next = NULL;
        temp->subordinate = NULL;

        // Assign created node to head's subordinate
        head->subordinate = temp;
        return;
    } else {
        // Create Temporary Node
        Node *temp = malloc(sizeof(Node));
        strcpy(temp->name, name);
        temp->next = NULL;
        temp->subordinate = NULL;

        // Add temp's next to current head subordinate
        temp->next = head->subordinate;

        // Replace current head subordinate with temp
        head->subordinate = temp;
        return;
    }
}

// printList function prints the organizational hierarchy recursively.
void printList(Node *head) {
    // Guard Clause
    if (head == NULL) {
        return;
    }

    // Print current head's name
    printf("Subordinate of %s: ", head->name);

    // Print all current head's subordinates
    Node *curr = head->subordinate;
    while (curr != NULL) {
        printf("%s -> ", curr->name);
        curr = curr->next;
    }
    printf("NULL\n");

    // Recursively call for all current head's subordinates
    curr = head->subordinate;
    while (curr != NULL) {
        printList(curr);
        curr = curr->next;
    }
}

// fireAll function frees all nodes in the organizational hierarchy recursively.
void fireAll(Node *head) {
    // Guard Clause
    if (head == NULL) {
        return;
    }

    // Recursively call for all current head's subordinates
    Node *curr = head->subordinate;
    while (curr != NULL) {
        fireAll(curr);
        curr = curr->next;
    }

    // frees current pointer head
    free(head);
}

int main() {

    /*
        Case's Statements
    */

    Node *ceo = createNode("Frieren");

    addSubordinate(ceo, "Eisen");
    addSubordinate(ceo, "Heiter");

    Node *manager1 = ceo->subordinate;
    addSubordinate(manager1, "Stark");

    Node *manager2 = ceo->subordinate->next;
    addSubordinate(manager2, "Fern");
    
    printList(ceo);

    fireAll(ceo);
    return 0;
}