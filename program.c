
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start, int target)
{
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        if (current == target)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

void DFSUtil(int current, int target, int *found)
{
    visited[current] = 1;
    printf("%d ", current);

    if (current == target)
        *found = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] && !visited[i])
            DFSUtil(i, target, found);
    }
}

void DFS(int start, int target)
{
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFSUtil(start, target, &found);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");
}

int main()
{
    int edges, u, v, start, target;

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter number of connections: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter connection (u v): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid node number.\n");
            return 1;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("Enter target file node: ");
    scanf("%d", &target);

    if (start < 0 || start >= n ||
        target < 0 || target >= n)
    {
        printf("Invalid starting or target node.\n");
        return 1;
    }

    BFS(start, target);
    DFS(start, target);

    return 0;
}
