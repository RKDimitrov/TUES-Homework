#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode get(LinkedList* list, int index){
	struct ListNode temp = *list->head;
	for(int i = 0; i < index; i++){
		if(temp.next == NULL){
			return NULL;
		}
		temp = temp->next;
	}
	return temp;
}

void pushfront(LinkedList * list, double value){
	struct ListNode *node = (node *) malloc(1, sizeof(struct ListNode));
	node->value = value;
	list->head->prev = &node;
	node->next = list->head;
	list->head = &node;
}
double popfront(LinkedList* list){
	struct ListNode *curHead = list.head;
	double value = head->value;
	list->head = head->next;
	free(head);
	return value;
}

void print(LinkedList* list){
	struct ListNode temp = *list->head;
	while(temp->next != NULL){
		printf("%lf", &temp->value);
		temp = temp->next;
	}
}
int main(){
	LinkedList* list;
	pushfront(&list, 1);
	pushfront(&list, 2);
	pushfront(&list, 3);
	pushfront(&list, 4);
	pushfront(&list, 5);

	print(list);
}
