typedef struct element
{
    int key;
    int data;
} element;

typedef struct treeNode *treePointer;
typedef struct treeNode
{
    element data;
    treePointer left, right;
} treeNode;

treePointer root;

element *search(treePointer tree, int k)
{
    if (!root)
        return NULL;
    if (k == root->data.key)
    {
        return &(root->data);
    }
    if (k > root->data.key)
    {
        return search(root->left, k);
    }
    else
    {
        return search(root->right, k);
    }
}

element *iterSearch(treePointer tree, int k)
{
    while (tree)
    {
        if (k == tree->data.key)
            return &(tree->data);
        if (k < tree->data.key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return NULL;
}

treePointer modifiedSearch(treePointer tree, int k)
{
    if (!tree)
    {
        return NULL;
    }
    while (tree)
    {
        if (k == tree->data.key)
            return NULL;
        if (k < tree->data.key)
        {
            if (tree->left)
                tree = tree->left;
        }
        else
        {
            if (tree->right)
                tree = tree->right;
        }
    }
    return tree;
}

void insert(treePointer *node, int k, int theItem)
{
    element data = {k, theItem};
    treePointer ptr, temp = modifiedSearch(*node, k);
    if (temp || !(*node)) // temp = NULL 이고 empty tree인 상황을 위해
    {
        ptr = (treePointer)malloc(sizeof(*ptr));
        ptr->data = data;
        if (*node)
        {
            if (k < temp->data.key)
            {
                temp->left = ptr;
            }
            else
            {
                temp->right = ptr;
            }
        }
        else
        {
            *node = ptr;
        }
    }
}