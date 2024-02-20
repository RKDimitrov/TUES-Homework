#include <stdio.h>
#include <stdlib.h>

typedef struct Node_S{
    char value;
    struct Node_S* left;
    struct Node_S* right;
}Node;

Node* initNode(char value){
    Node* root = malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    root->value = value;
    return root;
}

Node* push(Node* root, char value){
    if(root == NULL) return initNode(value);
    if (value > root->value){
        root->right = push(root->right, value);
        return root;
    }
    root->left = push(root->left, value);
    return root;
}

void counter(Node* root, int count[26]){
    if(!root) return;
    count[root->value - 'a']++;
    counter(root->left, count);
    counter(root->right, count);
}

void printSpaces(int spaces) {
    for (int i = 0; i < spaces; ++i) {
        printf(" ");
    }
}

void printTreeRecursive(Node* root, int level, char branch, int spaces) {
    if (root == NULL) {
        return;
    }

    spaces += 4;

    printTreeRecursive(root->right, level + 1, '/', spaces);

    printSpaces(spaces - 4);
    printf("%c--%c\n", branch, root->value);

    printTreeRecursive(root->left, level + 1, '\\', spaces);
}

void printTree(Node* root) {
    printTreeRecursive(root, 0, ' ', 0);
}

int main(){
    Node* root = initNode('v');
    push(root, 'g');
    push(root, 'a');
    push(root, 'z');
    push(root, 'z');
    printTree(root);
    
    int count[26] = {0};
    counter(root, count);
    for(int i = 25; i >= 0; i--){
        if(count[i] > 0) printf("%c - %d; ", i + 'a', count[i]);
    }
}