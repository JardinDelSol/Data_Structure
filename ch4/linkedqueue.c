#include <stdio.h>
#define MAX_QUEUE 10

typedef struct element
{
    int data;
} element;

typedef struct queue *queuePointer;
typedef struct queue
{
    element data;
    queuePointer link;
} queue;

queuePointer front[MAX_QUEUE], rear[MAX_QUEUE];

void addq(int i, element item)
{
    queuePointer temp;
    temp = (queuePointer)malloc(sizeof(*temp));
    temp->data = item;
    temp->link = NULL;
    if (front[i])
        rear[i]->link = temp;
    else
        front[i] = temp;
    rear[i] = temp;
}

element deleteq(int i)
{
    element result;
    queuePointer temp;
    temp = front[i];
    if (temp)
    {
        queueEmpty();
    }
    result = temp->data;
    front[i] = temp->link;
    free(temp);
    return result;
}