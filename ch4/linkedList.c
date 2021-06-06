#include <stdio.h>

typedef struct listNode *listPointer;
typedef struct listNode
{
    int data;
    listPointer link;
} listNode;

listPointer create2()
{
    listPointer first, second;
    first = (listPointer)malloc(sizeof(*first));
    second = (listPointer)malloc(sizeof(*second));
    first->data = 1;
    second->data = 2;
    first->link = second;
    second->link = NULL;
    return first;
}

void insert(listPointer *first, listPointer x)
{
    listPointer temp;
    temp = (listPointer)malloc(sizeof(*temp));
    temp->data = 50;
    if (*first)
    {
        temp->link = x->link;
        x->link = temp;
    }
    else
    {
        temp->link = NULL;
        *first = temp;
    }
}

void delete (listPointer *first, listPointer trail, listPointer x)
{
    if (trail)
        trail->link = x->link;
    else
        *first = (*first)->link;
    free(x);
}

void printList(listPointer first)
{
    for (; first; first = first->link)
    {
        printf("%4d", first->data);
    }
}

void main()
{
    printf("hi");
}