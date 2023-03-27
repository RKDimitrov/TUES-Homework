#include <stdio.h>
#include <stdlib.h>
#include "dynamicarr.h"

DynamicArray init(int capacity){
    DynamicArray arr;
    arr.capacity = capacity;
    arr.size = 0;
    arr.buffer =(int *) calloc(arr.capacity, sizeof(int));
    return arr;
}


void pushBack(DynamicArray * arr, int value){
    int newsize = arr->size + 1;
    if(newsize > arr->capacity){
        arr->capacity *= 2;
        arr->buffer = (int *) realloc(arr->buffer, arr->capacity * sizeof(int));
    }
    arr->size = newsize;
    arr->buffer[newsize - 1] = value;
}
int popBack(DynamicArray * arr){
    int value = arr->buffer[arr->size - 1];
    arr->size--;
    return value;
}

void pushFront(DynamicArray * arr, int value);
int popFront(DynamicArray * arr);

void setElement(DynamicArray * arr, int index, int value);
int getElement(DynamicArray * arr, int index){
    return arr->buffer[index];
}


int main(){
    
}