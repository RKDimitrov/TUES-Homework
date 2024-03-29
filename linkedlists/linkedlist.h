#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode{
    double value;
    struct ListNode * prev;
    struct ListNode * next;
};
typedef struct {
    int size;
    struct ListNode * head;
} LinkedList;

LinkedList init();

struct ListNode get(LinkedList * list, int index);
void sort(LinkedList * list);
void pushfront(LinkedList * list, double value);

double popfront(LinkedList * list);
#endif
