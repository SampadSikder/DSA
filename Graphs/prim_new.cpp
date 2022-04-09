#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int graph[N][N];
int key[N]; // distance from source
int prevv[N];
int EXTRACT_MIN(bool Q[], int nodes)
{
    int minn = INT_MAX, min_index;
    for (int i = 1; i <= nodes; i++)
    {
        if (Q[i] == false && key[i] <= minn)
        {
            minn = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void mst_prim(int source, int nodes)
{
    for (int i = 1; i <= nodes; i++)
    {
        key[i] = INT_MAX;
        prevv[i] = -1;
    }
    key[source] = 0;
    int in_Q = nodes;
    bool Q[N] = {false};

    while (in_Q--)
    {
        int u = EXTRACT_MIN(Q, nodes);
        Q[u] = true;
        for (int i = 1; i <= nodes; i++)
        {
            if (graph[u][i] != 0 && Q[i] == false)
            {
                if (graph[u][i] < key[i])
                {
                    prevv[i] = u;
                    key[i] = graph[u][i];
                }
            }
        }
    }
}
void print_tree(int dest)
{
    if (prevv[dest] == -1)
    {
        cout << dest << " ";
        return;
    }
    print_tree(prevv[dest]);
    cout << dest << " ";
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
        graph[v][u] = w;
    }

    mst_prim(1, nodes);
    print_tree(3);
}