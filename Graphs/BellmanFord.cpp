#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int graph[N][N];
int d[N]; // distance from source
int prevv[N];
struct node
{
    int src;
    int dest;
    int weight;
} edges[N];
void print_path(int nodes)
{
    for (int i = 1; i <= nodes; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= nodes; i++)
    {
        cout << prevv[i] << " ";
    }
}
void Bellman_Ford(int source, int nodes, int edge)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INT_MAX;
        prevv[i] = -1;
    }
    d[source] = 0;

    for (int i = 1; i <= nodes - 1; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            // Relaxation
            if (d[u] != INT_MAX && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                prevv[v] = u;
            }
        }
    }
    // if value changes then negative cycle present
    for (int i = 0; i < edge; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if (d[u] != INT_MAX && d[u] + w < d[v])
        {
            cout << "Negative cycle exists" << endl;
            return;
        }
    }
    print_path(nodes);
}
int main()
{
    int nodes, edge;
    cin >> nodes >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].src = u;
        edges[i].dest = v;
        edges[i].weight = w;
    }
    Bellman_Ford(1, nodes, edge);
}