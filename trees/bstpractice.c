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

int size(Node* root){
	if(root == NULL) return 0;
	return 1 + size(root->left) + size(root->right);
}

int isBST(Node* root){
	if(root == NULL) return 1;
	if(root->left && root->left->value > root->value) return 0;
	if(root->right && root->right->value < root->value) return 0;
	return isBST(root->left) && isBST(root->right);
}

int max(int a, int b){
	if(a > b) return a;
	return b;
}

int depth(Node* root){
	if(root == NULL) return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}

int isIdentity(Node* tree1, Node* tree2){
	if(!tree1 && !tree2) return 1;
	if(!tree1 || !tree2) return 0;
	if(tree1->value != tree2->value) return 0;
	return isIdentity(tree1->left, tree2->left) * isIdentity(tree1->right, tree2->right);
}

int subTree(Node* tree1, Node* tree2){
	if(!tree2) return 1;
	if(!tree1) return 0;
	return isIdentity(tree1, tree2) + subTree(tree1->right, tree2) + subTree(tree1->left, tree2);
}

int main(){
    	Node* root = initNode(5);
	Node* root2 = initNode(3);

	push(root2, 2);
	push(root2, 4);
    	push(root, 3);
	push(root, 2);
	push(root, 6);
	printTree(root);

	printf("\nTREE SIZE: %d", size(root));
	printf("\nIsBST: %d", isBST(root));
	printf("\nDepth of Tree: %d", depth(root));
	printf("\nIs Identity: %d", isIdentity(root, root2));
	printf("\nIs subTree: %d", subTree(root, root->left->left));
}
