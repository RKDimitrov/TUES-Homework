#include <stdio.h>

typedef struct Node{
    int value;
    node *xor;
}

node* xor(node *p1, node *p2){
	return (node*)(size_t) p1 ^ (size_t)p2;
}
int main(){
	Node* node1 = malloc(sizeof(Node));
	Node* node2 = malloc(sizeof(Node));
	Node* node3 = malloc(sizeof(Node));
	node1->value = 5;
	node2->value = 10;
	node3->value = 7;
	node1->xor = node2;
	node2->xor = xor(node1, node3);
	node3->xor = node2;
}
