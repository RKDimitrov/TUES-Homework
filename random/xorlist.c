#include <stdio.h>
#include <stdlib.h>

typedef struct Node_S{
	int value;
	struct Node_S* xor;
}Node;

Node* xor(Node* p1, Node* p2){
	return (Node*)((size_t)p1 ^ (size_t)p2);
}

Node* pushFront(Node *head, int value){
	Node* node = malloc(sizeof(Node));
	node->value = value;
	node->xor = xor(NULL, head);
	head->xor = xor(node, head->xor);
	return node;
}

Node* popFront(Node* head){
	Node* temp = xor(NULL, head->xor);
	temp->xor = xor(head, temp->xor);
	free(head);
	// NULL - NEW - HEAD - NEXT
	return temp;
}

int containsIter(Node* head, int search){
	Node* prevNode = NULL;
	while(head != NULL){
		if(head->value == search)return 1;
		Node* temp = head;
		head = xor(prevNode, head->xor);
		prevNode = temp;
	}
	return -1;
}

int containsRec(Node* head, Node* prevNode, int search){
	if(head == NULL)return -1;
	if(head->value == search)return 1;
	return containsRec(xor(prevNode, head->xor), head, search);
}

void printList(Node* head){
	Node* prevNode = NULL;
	while(head != NULL){
		printf("%d ", head->value);
		Node* temp = prevNode;
		prevNode = head;
		head = xor(temp, prevNode->xor);
	}
}

int main(){
	Node* head = malloc(sizeof(Node));
	head->value = 6;
	head->xor = NULL;
	
	for(int i = 5; i > 0 ; i--){
		head = pushFront(head, i);
	}

	printList(head);
	head = popFront(head);
	printList(head);
	printf("\nIter. did find number?: %d", containsIter(head, 5));

	Node* prevNode = NULL;
	printf("\nRec. did find number?: %d", containsRec(head, prevNode, 8));

}