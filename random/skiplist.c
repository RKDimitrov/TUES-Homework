#include <stdio.h>
#include <stdlib.h>

typedef struct Node_S{
    int value;
    struct Node_S* next;
    struct Node_S* skip;
}Node;

void printList(Node* head){
    while(head != NULL){
        printf("%d ", head->value);
        head = head->next; 
    }
}

int contains(Node* head, int search){
    while(head != NULL){
        if(head->value == search)return 1;
        head = head->next;
    }
    return -1;
}

Node* insert(Node* head, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL || newNode->value < head->value) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;

    while (current->next != NULL && newNode->value > current->next->value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main(){
    Node* head = malloc(sizeof(Node));
    Node* head2 = malloc(sizeof(Node));
    head->value = 4;
    head->next = head2;
    head2->value = 5;
    head2->next = NULL;

    printList(head);
    printf("\n%d ", contains(head, 3));

    insert(head, 4);
    printList(head);

}