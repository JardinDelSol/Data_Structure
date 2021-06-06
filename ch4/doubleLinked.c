#include <stdio.h>

typedef struct element
{
    int data;
} element;
typedef struct node *nodePointer;
typedef struct node
{
    nodePointer llink;
    element data;
    nodePointer rlink;
} node;

void insert(nodePointer node, nodePointer newnode)
{
    newnode->llink = node;
    newnode->rlink = node->rlink;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}

void delete (nodePointer node, nodePointer deleted)
{
    if (node == deleted)
    {
        listEmpty();
    }
    node->rlink = deleted->rlink;
    deleted->rlink->llink = node;
    free(deleted);
}