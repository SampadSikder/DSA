#include <bits/stdc++.h>
using namespace std;
#define NIL -1
const int N = 100;
const int INF = 1e9 + 5;
int key[N];
int parent[N];
int weight[N][N];
bool Q[N];

// vector<int> adj_list[N];

void mst_prim(int root, int vertex)
{
    for (int i = 1; i <= vertex; i++)
    {
        key[i] = INF;
        parent[i] = NIL;
    }
    key[root] = 0;
    int in_Q = v; // bortomane koyta vertex ase
    for (int i = 1; i <= vertex; i++)
    {
        Q[i] = true;
    }
    while (in_Q > 0)
    {
        int u = NIL;
        for (int i = 1; i <= vertex; i++)
        {
            if (Q[i] == true && key[i] < key[u])
            {
                u = i; // queue er minimum key er vertex
            }
        }
        Q[u] = false;
        in_Q--;
        for (int i = 1; i <= vertex; i++)
        {
            if (Q[i] == true && weight[u][i] != 0)
            {
                if (weight[u][i] < key[i])
                {
                    key[i] = weight[u][i];
                    parent[i] = u;
                }
            }
        }
    }
}
void print_path(int u)
{
    if (parent[u] == -1)
    {
        return;
    }
    print_path(parent[u]);
}

int main()
{
    int vertex, edge; // number of vertices and edges
    cin >> vertex >> edge;

    for (int i = 1; i <= edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        weight[u][v] = w; // weight input nitesi graph er jonno
        weight[v][u] = w; // bi direction
    }

    mst_prim(1, vertex);
    print_path(vertex);
}