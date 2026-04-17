#include <stdio.h>

int adj[100][100], visited[100], n, m;

void dfs(int v)
{
    visited[v] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int u, v, count = 0;

    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges:\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    }

    printf("Number of connected components: %d\n", count);

    return 0;
}