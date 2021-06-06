typedef struct element
{
    int key;
    int data;
} element;

void adjust(element a[], int root, int n) //root = subtree's root
{
    int child, rootkey;
    element temp;
    temp = a[root];
    rootkey = a[root].key;
    child = 2 * root;
    while (child <= n)
    {
        if ((child < n) && (a[child].key < a[child + 1].key))
            child++;
        if (rootkey > a[child].key) //rootkey == a[child/2].key
            break;
        a[child / 2] = a[child];
        child *= 2;
    }
    a[child / 2] = temp;
}

void heapSort(element a[], int n)
{
    int i, j;
    element temp;

    for (i = n / 2; i > 0; i--)
    {
        adjust(a, i, n);
    }
    for (i = n - 1; i > 0; i--)
    {
        SWAP(a[1], a[i]);
        adjust(a, 1, i);
    }
}