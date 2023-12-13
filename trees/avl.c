#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node_S{
	int value;
	struct Node_S* right;
	struct Node_S* left;
	int height;
}Node;

Node* initNode(int value){
	Node* node = malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	node->height = 0;
	return node;
}

uint8_t h(Node* n){
	if(!n) return 0;
	return n->height;
}

int max(int a, int b){
	if(a > b) return a;
	return b;
}

Node* insert(Node* root, int value){
	Node* node = initNode(value);
	if(!root) return node;
	if(node->value > root->value){
		root->right = insert(root->right, value);
	}else{
		root->left = insert(root->left, value);
	}

	int diff = h(root->left) - h(root->right);
	if(diff > 1){
	//	root = right_rotation(root);
	}else if(diff < -1){
	//	root = left_rotation(root);
	}
	root->height = max(h(root->left), h(root->right)) + 1;

	return root;
}

Node* left_rotation(Node* root){
	if(root->right->right){
		Node* buffer = root;
		root = root->right;
		root->left = buffer;
		root->left->right = NULL;
		return root;
	}
	return NULL;
}

Node* right_rotation(Node* root){
	if(root->left->left){
		Node* buffer = root;
		root = root->left;
		root->right = buffer;
		root->right->left = NULL;
		return root;
	}
	return NULL;
}

void printSpaces(int spaces) {
    for(int i = 0; i < spaces; i++){
        printf(" ");
    }
}

void printTreeRecursive(Node* root, int level, char branch, int spaces){
    if(!root) return;
    spaces += 4;
    printTreeRecursive(root->right, level + 1, '/', spaces);
    printSpaces(spaces - 4);
    printf("%c--%d\n", branch, root->value);
    printTreeRecursive(root->left, level + 1, '\\', spaces);
}

void printTree(Node* root){
    printTreeRecursive(root, 0, ' ', 0);
}

void ezPrintTree(Node* root){
	if(!root) return;
	printf("%d\n", root->value);
	if(root->right) return ezPrintTree(root->right);
	if(root->left) return ezPrintTree(root->left);
}

int main(){
	Node* root = initNode(5);
	insert(root, 10);
	insert(root, 16);

	//printTree(root);
	ezPrintTree(root);
	root = left_rotation(root);
	//printTree(root);
	printf("Rotated left: \n");
	ezPrintTree(root);
	return 0;
}
