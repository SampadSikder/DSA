#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
const int N = 100;
int graph[N][N];
void floyd_warshall(int vertices)
{
    int matrix[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = graph[i][j];
        }
    }
    for (int k = 1; k <= vertices; k++)
    {
        for (int i = 1; i <= vertices; i++)
        {
            for (int j = 1; j <= vertices; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = matrix[i][j];
        }
    }
}
void print_matrix(int vertices)
{
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            if (graph[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    freopen("floyd_warshall.txt", "r", stdin);
    int edges, vertices;
    cin >> vertices >> edges;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = INF;
        }
    }
    for (int i = 1; i <= vertices; i++)
    {
        graph[i][i] = 0;
    }
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    floyd_warshall(vertices);
    print_matrix(vertices);
}