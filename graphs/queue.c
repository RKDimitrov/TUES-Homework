#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {
    void* data;
    struct queueNode* next;
} queueNode;

// Structure to represent a queue
typedef struct {
    queueNode* front;
    queueNode* rear;
} Queue;

// Function to create a new node
queueNode* createQueueNode(void* value) {
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to insert an element into the queue
void insertQueue(Queue* q, void* value) {
    queueNode* newNode = createQueueNode(value);
    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the queue
void* popQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot remove element.\n");
        exit(EXIT_FAILURE);
    }
    void* removedItem = q->front->data;
    queueNode* temp = q->front;
    q->front = q->front->next;
    free(temp);
    return removedItem;
}

// Function to peek at the front element of the queue
void* peekQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        exit(EXIT_FAILURE);
    }
    return q->front->data;
}

