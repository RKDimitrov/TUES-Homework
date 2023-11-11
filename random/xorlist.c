#include <stdio.h>
#include <stdlib.h>

struct Node{
    int head;
    struct Node *xor;
};

struct Node* xor(struct Node *p1, struct Node *p2){
	return (struct Node*)((size_t) p1 ^ (size_t)p2);
}

int containsIter(struct Node* head, int search){
	int prevNode = NULL;
	while(head != NULL){
		if(head == NULL)return -1;
		if(head == search){
			return 1;
		}else{
			int temp = head;
			head = xor(prevNode, head->xor);
			prevNode = temp;
		}
	}
}

int main(){
	struct Node* node1 = malloc(sizeof(struct Node));
	struct Node* node2 = malloc(sizeof(struct Node));
	struct Node* node3 = malloc(sizeof(struct Node));
	node1->head = 5;
	node2->head = 10;
	node3->head = 7;
	node1->xor = node2;
	node2->xor = xor(node1, node3);
	node3->xor = node2;
	containsIter(node1->head,2);
}
