#include <iostream>
using namespace std;

struct Vector
{
    int capacity;
    int size;
    int *array;
};

void printVector(Vector *vector)
{
    for (int i = 0; i < vector->size; i++)
    {
        cout << vector->array[i];
    }
    cout << endl;
}

void createVector(Vector *vector, int capacity, int size)
{
    vector->size = size;
    vector->capacity = capacity;
    vector->array = new int[size];
}

void add(Vector *vector, int value)
{
    if (vector->size == vector->capacity)
    {
        vector->capacity = vector->capacity * 2;
        vector->array = new int[vector->capacity];
        int *newArray = new int[vector->capacity];
        for (int i = 0; i < vector->size; i++)
        {
            newArray[i] = vector->array[i];
        }
        delete[] vector->array;
        vector->array = newArray;
    }

    vector->array[vector->size] = value;
    vector->size++;
}

void deleteVector(Vector *vector)
{
    delete[] vector->array;
    delete vector;
}

void removeFirstElement(Vector *vector)
{
    if (!vector->array[0])
    {
        cout << "There's no first element" << endl;
        return;
    }

    for (int i = 0; i < vector->size - 1; i++)
    {
        vector->array[i] = vector->array[i + 1];
    }
    vector->size--;
}

void removeLastElement(Vector *vector)
{
    vector->size--;
}

void removeElement(Vector *vector, int index)
{
    if (index < 0 || index >= vector->size)
    {
        cout << "Trying to remove index out of bonds" << endl;
        return;
    }
    // int data = vector->array[index];
    for (int i = index; i < vector->size - 1; i++)
    {
        vector->array[i] = vector->array[i + 1];
    }
    vector->size--;
    return; // data;
}

int main()
{
    Vector *vector = new Vector;
    createVector(vector, 5, 0);

    add(vector, 3);
    add(vector, 5);
    add(vector, 7);

    printVector(vector);
    removeFirstElement(vector);
    removeLastElement(vector);
    printVector(vector);
    removeElement(vector, 0);
    printVector(vector);
    return 0;
}