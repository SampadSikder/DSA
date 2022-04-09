#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int graph[N][N];
int d[N]; // distance from source
int prevv[N];

void initialize_single_source(int source)
{
    for (int i = 0; i < N; i++)
    {
        d[i] = INT_MAX;
        prevv[i] = -1;
    }
    d[source] = 0;
}
int EXTRACT_MIN(bool Q[], int nodes)
{
    int minn = INT_MAX, min_index;
    for (int i = 1; i <= nodes; i++)
    {
        if (Q[i] == false && d[i] <= minn)
        {
            minn = d[i];
            min_index = i;
        }
    }
    return min_index;
}
void RELAX(int u, int v)
{
    if (d[v] > d[u] + graph[u][v]) // cumulative distance
    {
        d[v] = d[u] + graph[u][v];
        prevv[v] = u;
    }
}
void dijkstra(int source, int nodes)
{
    initialize_single_source(source);
    bool Q[N] = {false}; // to determine visited/not visited index
    int in_Q = nodes;

    while (in_Q--)
    {
        int u = EXTRACT_MIN(Q, nodes);
        Q[u] = true;
        for (int i = 1; i <= nodes; i++)
        {
            if (graph[u][i] != 0 && Q[i] == false)
            {
                RELAX(u, i);
            }
        }
    }
}
void print_solution(int nodes)
{
    for (int i = 1; i <= nodes; i++)
    {
        cout << "Shortest path from source: " << i << "=" << d[i] << endl;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int nodes, edges;
    cin >> nodes >> edges;
    int u, v, w;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    // initialize_single_source(1);

    dijkstra(1, nodes);
    print_solution(nodes);
}