#define TRUE 1
#define FALSE 0

typedef struct node *nodePointer;
typedef struct node
{
    int vertex;
    nodePointer link;
} node;

nodePointer graph[10];

void dfs(int v)
{
    nodePointer w;
    int visited[10];
    visited[v] = TRUE;
    printf(v);
    for (w = graph[v]; w; w = w->link)
    {
        if (!visited[w->vertex])
            dfs(w->vertex);
    }
}

void bfs(int v)
{
    nodePointer w;
}