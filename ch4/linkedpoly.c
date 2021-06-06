#include <stdio.h>

typedef struct polyNode *polyPointer;
typedef struct polyNode
{
    int coef;
    int expon;
    polyPointer link;
} polyNode;

polyPointer padd(polyPointer a, polyPointer b)
{
    polyPointer c, rear, temp;
    int sum;
    rear = (polyPointer)malloc(sizeof(*rear));
    c = rear;
    while (a && b)
    {
        switch (COMPARE(a->expon, b->expon))
        {
        case -1:
            attatch(b->coef, b->expon, &rear);
            b = b->link;
            break;

        case 0:
            sum = a->coef + b->coef;
            if (sum != 0)
            {
                attatch(sum, a->coef, &rear);
            }
            a = a->link;
            b = b->link;
            break;

        case 1:
            attatch(a->coef, a->expon, &rear);
            a = a->link;
            break;
        }
    }
    while (a)
    {
        attach(a->coef, a->expon, &rear);
    }
    for (; b; b = b->link)
    {
        attach(b->coef, b->expon, &rear);
    }
    temp = c;
    c = c->link;
    free(temp);
    return c;
}

void attach(float coefficient, int exponent, polyPointer *ptr)
{
    polyPointer temp;
    temp = (polyPointer)malloc(siezeof(*temp));
    temp->coef = coefficient;
    temp->expon = exponent;
    temp->link = NULL;
    (*ptr)->link = temp;
    (*ptr) = temp;
}

void erase(polyPointer *ptr)
{
    polyPointer temp;
    while (*ptr)
    {
        temp = *ptr;
        (*ptr) = (*ptr)->link;
        free(temp);
    }
}

polyPointer avail; //first Node of circualr list of free nodes

polyPointer getNode(void)
{
    polyPointer node;
    if (avail)
    {
        node = avail;
        avail = avail->link;
    }
    else
        node = (polyPointer)malloc(sizeof(*node));
    return node;
}

void returnNode(polyPointer node)
{
    node->link = avail;
    avail = node;
}

void cerase(polyPointer *ptr)
{
    polyPointer temp;
    if (*ptr)
    {
        temp->link = (*ptr)->link;
        (*ptr)->link = avail;
        avail = temp;
        ptr = NULL;
    }
}

polyPointer cpadd(polyPointer a, polyPointer b)
{
    polyPointer c, lastC, startA;
    int sum, done = 0;
    startA = a;
    a = a->link;
    b = b->link;
    c = getNode();
    c->expon = -1;
    lastC = c;
    do
    {
        switch (COMPARE(a->expon, b->expon))
        {
        case -1:
            attatch(b->coef, b->expon, &lastC);
            b = b->link;
            break;

        case 0:
            if (startA == a)
                done = 1;
            sum = a->coef + b->coef;
            if (sum != 0)
            {
                attatch(sum, a->coef, &lastC);
            }
            a = a->link;
            b = b->link;
            break;

        case 1:
            attatch(a->coef, a->expon, &lastC);
            a = a->link;
            break;
        }
    } while (!done);
    lastC->link = c;
    return c;
}