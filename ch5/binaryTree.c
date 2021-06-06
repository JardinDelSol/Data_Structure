typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
} node;

void inorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        printf(ptr->data);
        inorder(ptr->rightChild);
    }
}

void preorder(treePointer ptr)
{
    if (ptr)
    {
        printf(ptr->data);
        inorder(ptr->leftChild);
        inorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        inorder(ptr->rightChild);
        printf(ptr->data);
    }
}

void iterIndorder(treePointer node)
{
    treePointer stack[100];
    int top = 0;
    while (1)
    {
        for (; node; node = node->leftChild)
            push(node);
        node = pop();
        if (node)
            break;
        print(node->data);
        node = node->rightChild;
    }
}

void levelOrder(treePointer ptr)
{
    treePointer queue[100];
    int front = 0, rear = 0;
    if (!ptr)
        return;
    addq(ptr);
    while (1)
    {
        ptr = deleteq();
        if (ptr)
        {
            printf(ptr->data);
            if (ptr->leftChild)
                addq(ptr->leftChild);
            if (ptr->rightChild)
                addq(ptr->rightChild);
        }
        else
        {
            break;
        }
    }
}

treePointer copy(treePointer original)
{
    treePointer temp;
    if (original)
    {
        temp = (treePointer)malloc(sizeof(*temp));
        temp->data = original->data;
        temp->leftChild = copy(original->leftChild);
        temp->rightChild = copy(original->rightChild);
        return temp;
    }
    return NULL;
}

int equal(treePointer first, treePointer second)
{
    return ((!first && !second) || (first && second && first->data == second->data && equal(first->leftChild, second->leftChild) && equal(first->leftChild, second->rightChild)));
}