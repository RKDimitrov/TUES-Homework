#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

#include "queue.c"

struct edge_t{
	struct node_t *dest;
};

typedef struct node_t{
	int value;
	int eSize;
	struct edge_t* edges;
}Node;

Node* initNode(int value){
	Node *node = malloc(sizeof(Node));
	node->eSize = 0;
	node->value = value;
	return node;
}

void connectNodes(Node *node1, Node *node2){
	node1->edges = realloc(node1->edges, node1->eSize+1);
	node1->edges[node1->eSize++] = (struct edge_t){node2};

	node2->edges = realloc(node2->edges, node2->eSize+1);
	node2->edges[node2->eSize++] = (struct edge_t){node1};
}

void insertInChecked(Node** array, Node* value, int* count, int* size){
	if(*count < *size){
		*size *= 2;
		array = realloc(array, *size * sizeof(Node*));
	}
	array[*count++] = value; 
}

int isElementInArray(void** array, void* value, int size){
	for(int i = 0; i < size; i++){
		if(array[i] == value){
			return 1;
		}
	}
	return 0;
}

void printGraph(Node* root){
	Node** isCheckedArray = malloc(sizeof(Node*));
	int count = 0;
	int size = 1;

	Queue* queue;
	insertQueue(queue, root);

	while(!isQueueEmpty(queue)){
		Node* current = (Node*) popQueue(queue);
		if(isElementInArray((void**)isCheckedArray, current, count)){
			continue;
		}
		printf("%d", current->value);
		insertInChecked(isCheckedArray, current, &count, &size);
		for(int i = 0; i < current->eSize; i++){
			insertQueue(queue, current->edges[i].dest);
		}
	}
}

int main(){
	Node* node1 = initNode(5);
	Node* node2 = initNode(7);

	connectNodes(node1,node2);
	printGraph(node1);
}
