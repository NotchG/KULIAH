#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    struct Tree *left, *right;
} Tree;

Tree * createNode(int value) {
    Tree *temp = malloc(sizeof(Tree));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

Tree * insertNode(Tree *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left =  insertNode(root->left, value);
    } else if (value > root->data) {
        root->right =  insertNode(root->right, value);
    }
    return root;
}

Tree *searchNode(Tree *root, int target) {
    if (root == NULL || root->data == target) {
        return root;
    }
    if (root->data > target) {
        return searchNode(root->left, target);
    }
    return searchNode(root->right, target);
}

Tree *findMin(Tree *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left != NULL) {
        return findMin(root->left);
    }
    return root;
}

Tree *Delete(Tree *root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (target > root->data) {
        root->right = delete(root->right, target);
    } else if (target < root->data) {
        root->left = delete(root->left, target);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if(root->left == NULL || root->right == NULL) {
            Tree *temp = NULL;
            if (root->left == NULL) {
                temp = root->right;
            } else if (root->right == NULL) {
                temp = root->left;
            }
            free(root);
            return temp;
        } else {
            Tree *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, target);
        }
    }
    return root;
}

void preOrder(Tree *root) {
    if (root == NULL) return;
    printf(" %d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Tree *root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 60);
    insertNode(root, 90);
    insertNode(root, 80);


    preOrder(root);

    return 0;
}