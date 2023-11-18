#include <stdio.h>
#include <stdlib.h>

typedef struct Node_S{
    int value;
    struct Node_S* left;
    struct Node_S* right;
}Node;

Node* initNode(int value){
    Node* root = malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    root->value = value;
    return root;
}

void printTree(Node* root){
    if(root == NULL) return;
    printf("%d\n", root->value);
    if(root->left) printTree(root->left);
    if(root->right) printTree(root->right);
}

Node* push(Node* root, int value){
    if(root == NULL) return initNode(value);
    if (value > root->value){
        root->right = push(root->right, value);
        return root;
    }
    root->left = push(root->left, value);
    return root;
}

int main(){
    Node* root = initNode(5);
    push(root, 6);
    push(root, 3);
    push(root, 7);
    printTree(root);
}