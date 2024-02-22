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

float weightProduct(Node* root, float *sumProduct, int *sumWeight){
	if(!root) return 0;
	int curWeight = weightProduct(root->left, sumProduct, sumWeight) + weightProduct(root->right, sumProduct, sumWeight);
	*sumProduct += root->value * curWeight;
	*sumWeight += curWeight;
	return curWeight + 1;
}

float avgWeight(Node* root){
	float sumProduct = 0;
	int sumWeight = 0;
	weightProduct(root, &sumProduct, &sumWeight);
	return sumProduct / sumWeight;
}

int main(){
    	Node* root = initNode(5);

    	root->left = initNode(1);
	root->right = initNode(7);
	root->left->right = initNode(3);
	root->right->right = initNode(12);
	root->right->right->right = initNode(3.14);

	printTree(root);

	printf("%f", avgWeight(root));
}
