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

void ezPrintTree(Node* root){
    if(root == NULL) return;
    printf("%d\n", root->value);
    if(root->left) ezPrintTree(root->left);
    if(root->right) ezPrintTree(root->right);
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
    printf("%c--%d\n", branch, root->value);

    printTreeRecursive(root->left, level + 1, '\\', spaces);
}

void printTree(Node* root) {
    printTreeRecursive(root, 0, ' ', 0);
}

int returnN(Node* root, int n){
	if(!root) return 0;
	
	if(root->right) returnN(root->right->value, n);
	
	return n;
}

int main(){
    	Node* root = initNode(5);
	Node* root2 = initNode(3);

	push(root2, 2);
	push(root2, 4);
    	push(root, 3);
	push(root, 6);
	printTree(root);
}
