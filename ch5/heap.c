#include <stdio.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct element
{
    int key;
} element;

element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int *n)
{
    int i;
    if (HEAP_FULL(*n))
    {
        exit();
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap[i / 2].key))
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
}

element pop(int *n)
{
    int parent, child;
    element item, temp;
    if (HEAP_EMPTY(*n))
    {
        exit();
    }
    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while (child <= *n)
    {
        if ((child < *n) && (heap[child].key < heap[child + 1].key))
        {
            child += 1;
        }
        if (temp.key >= heap[child].key)
            break;
        heap[parent] = heap[child];
        parent = child;
        child = parent * 2;
    }
    heap[parent] = temp;
    return item;
}

