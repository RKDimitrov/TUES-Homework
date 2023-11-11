#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
    struct Node* skip;
};

struct Node* insert(struct Node* node1, int newValue){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->value = newValue;
	node1->next = newNode;
	newNode->next = node1->skip;
	return newNode;
}

void printList(struct Node* node1){
	struct Node* temp = node1;
	while(node1 != NULL){
		printf("%d", temp->value);
		temp = temp->next;
	}
}

int main(){
	struct Node* node1 = malloc(sizeof(struct Node));
	struct Node* node2 = malloc(sizeof(struct Node));
	struct Node* node3 = malloc(sizeof(struct Node));

	node1->value = 2;
	node2->value = 7;
	node3->value = 8;

	node1->next = node2;
	node2->next = node3;
	node3->skip = NULL;

	node1->skip = node3;
	node2->skip = NULL;
	node3->skip = NULL;

	int newValue = 3;
	insert(node1, newValue);

	printList(node1);
}
