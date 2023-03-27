#ifndef DYNAMICARR_H
#define DYNAMICARR_H

typedef struct{
    int *buffer;
    unsigned int size;
    unsigned int capacity;
}DynamicArray

DynamicArray init(int capacity);
void pushBack(DynamicArray * arr, int value);
int popBack(DynamicArray * arr);

void pushFront(DynamicArray * arr, int value);
int popFront(DynamicArray * arr);

void setElement(DynamicArray * arr, int index, int value);
int getElement(DynamicArray * arr, int index);

#endif