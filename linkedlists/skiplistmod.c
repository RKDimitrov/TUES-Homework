#include <stdio.h>
#include <stdlib.h>

typedef struct Node_S{
    int value;
    struct Node_S* xor;
    struct Node_S* skip_xor;
}Node;

typedef struct{
    Node* head;
    Node* tail;
}List;

Node* xor(Node* p1, Node* p2){
    return (Node*)((size_t)p1 ^ (size_t)p2);
}

Node* initNode(int value){
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->xor = NULL;
    node->skip_xor = NULL;
    return node;
}

List* makeList(){
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL; 
    return list;
}

void* insert(List *list, int value){
    Node *node = initNode(value);
    
    if(list->head == NULL){
        list->head = node;
        list->tail = node;
        return list;
    }

    Node *prevPrev = NULL;
    Node *prev = NULL;
    Node *curr = list->head;

    while(1){
        if(value < curr->value){
            Node *next = xor(prev, curr->xor);
            node->xor = xor(prev, curr);
            node->skip_xor = xor(prevPrev, next);
            curr->xor = xor(node, next);
            curr->skip_xor = xor(prev, xor(prevPrev, curr->skip_xor));
 
            if(next) next->skip_xor = xor(xor(next->skip_xor, prev), node);
            if(prevPrev) prevPrev->skip_xor = xor(xor(prevPrev->skip_xor, curr), node);
            if(prev){
                prev->xor = xor(prevPrev, node);
                prev->skip_xor = xor(xor(prev->skip_xor, next), curr);
            }else{
                list->head = node;
            }
            break;
        }
 
        if(xor(curr->xor, prev) == NULL){
            node->xor = xor(curr, NULL);
            node->skip_xor = xor(prev, NULL);
            curr->xor = xor(curr->xor, node);
            list->tail = node;
            if (prev) prev->skip_xor = xor(prev->skip_xor, node);
            break;
        }
 
        Node *skip = xor(prevPrev, curr->skip_xor);
 
        if(skip && (value >= skip->value)){
            prevPrev = curr;
            prev = xor(prev, curr->xor);
            curr = skip;
            continue;
        }
        Node *next = xor(prev, curr->xor);
        prevPrev = prev;
        prev = curr;
        curr = next;
    }
}

void removeNode(List* list, int value){
    Node* prevPrev = NULL;
    Node* prev = NULL;
    Node* curr = list->head; 
    
    while(curr != NULL){
        if(curr->value == value){
            Node* next = xor(prev, curr->xor);
            Node* skip = xor(prevPrev, curr->skip_xor);
            if(prev){
                prev->xor = xor(prevPrev, next);
                prev->skip_xor = xor(xor(prev->skip_xor, next), skip);
            }
            if(next){
                next->xor = xor(prev, skip);
                next->skip_xor = xor(prevPrev, xor(prev, skip->skip_xor));
            }
            if(prevPrev) prevPrev->skip_xor = xor(xor(prevPrev->skip_xor, curr), next);
            if(skip) skip->skip_xor = xor(prev, xor(skip->skip_xor, curr));
            if(curr == list->head) list->head = next;
            if(curr == list->tail) list->tail = prev;
            free(curr);
            return;
        }
        Node* skip = xor(prevPrev, curr->skip_xor);
        if(skip && (value >= skip->value)){
            prevPrev = curr;
            prev = xor(prev, curr->xor);
            curr = skip;
            continue;
        }
        Node* next = xor(prev, curr->xor);
        prevPrev = prev;
        prev = curr;
        curr = next;
    }
}

int contains(List* list, int value){
    Node* prevPrev = NULL;
    Node* prev = NULL;
    Node* curr = list->head;

    while (curr != NULL)
    {
        if(curr->value == value) return 1;

        Node* skip = xor(prevPrev, curr->skip_xor);
        if(skip && (value >= skip->value)){
            prevPrev = curr;
            prev = xor(prev, curr->xor);
            curr = skip;
            continue;
        }
        Node* next = xor(prev, curr->xor);
        prevPrev = prev;
        prev = curr;
        curr = next;
    }
    return -1;
}

void rearrange(List *list){
    Node* prevPrev = NULL;
    Node* prev = NULL;
    Node* curr = list->head;
    Node* next = xor(prev, curr->xor);
    Node* skip = next ? xor(curr, next->xor) : NULL;

    while (curr){
        curr->skip_xor = xor(prevPrev, skip);
        prevPrev = prev;
        prev = curr;
        curr = next;
        next = skip;
        skip = next ? xor(curr, next->xor) : NULL;
    }
}

void printList(List* list){
    Node* prevPrev = NULL;
    Node* prev = NULL;
    Node* curr = list->head;
    Node* next = xor(prev, curr->xor);

    while(curr != NULL){
        printf("%d ", curr->value);
        Node *next = xor(prev, curr->xor);
        Node *skip = next ? xor(curr, next->xor) : NULL;
        prev ? printf("prev:%d ", prev->value) : printf("prev:NULL ");
        next ? printf("next:%d ", next->value) : printf("next:NULL ");
        xor(curr->skip_xor, skip)
            ? printf("skip_prev:%d ", xor(curr->skip_xor, skip)->value)
            : printf("skip_xor:NULL ");
        xor(prevPrev, curr->skip_xor)
            ? printf("skip_next:%d\n", xor(prevPrev, curr->skip_xor)->value)
            : printf("skip_next:NULL\n");
        prevPrev = prev;
        prev = curr;
        curr = next;
    }
}

int main(){
    List* list = makeList();
    for(int i = 0; i < 10; i++){
        insert(list, i);
    }

    printList(list);

    printf("\nContains: %d\n", contains(list, 6));

    removeNode(list, 6);
    printf("\nContains: %d\n", contains(list, 6));

    printList(list);
}