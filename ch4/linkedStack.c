#include <stdio.h>
#define MAXSTACK 10

typedef struct element
{
    int data;
} element;

typedef struct stack *elementPointer;

typedef struct stack
{
    element data;
    elementPointer link;
} stack;

elementPointer top[MAXSTACK];

void push(int i, element item)
{
    elementPointer temp;
    temp = (elementPointer)malloc(sizeof(*temp));
    temp->data = item;
    temp->link = top[i];
    tep[i] = temp;
}

element pop(int i)
{
    elementPointer temp = top[i];
    element item;
    if (temp)
        return stackEmpty();
    item = temp->data;
    top[i]->link = temp->link;
    free(temp);
    return item;
}
