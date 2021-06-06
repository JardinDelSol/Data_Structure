#include <stdio.h>

typedef struct element
{
    int data;
} element;

typedef struct node *nodePointer;
typedef struct node
{
    element data;
    nodePointer link;
} node;

nodePointer invert(nodePointer lead)
{
    nodePointer temp, trail;
    temp = NULL;
    while (lead)
    {
        trail = temp;
        temp = lead;
        lead = lead->link;
        temp->link = trail;
    }
    return temp;
}

nodePointer concatenate(nodePointer ptr1, nodePointer ptr2)
{
    nodePointer temp;
    if (!ptr1 || !ptr2)
        return NULL; // or return which ever is not empty
    temp = ptr1;
    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = ptr2;

    return ptr1;
}

void insertFront(nodePointer *last, nodePointer node)
{
    if (!last)
    {
        *last = node;
        node->link = node;
    }
    else
    {
        node->link = (*last)->link;
        (*last)->link = node;
    }
}

int length(nodePointer last)
{
    nodePointer temp;
    int count = 0;
    temp = last;
    if (last)
    {
        do
        {
            count++;
            temp = temp->link;
        } while (temp != last);
    }
    return count;
}