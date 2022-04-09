#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int graph[N][N] = {-1};
int parent[N];
int rGraph[N][N];
int V;
struct Queue
{
    int q[N + N];
    int front;
    int back;

    int size;

    Queue()
    {
        front = 0;
        back = 0;
        size = 0;
    }
    bool empty()
    {
        return size == 0;
    }
    void push(int x)
    {
        q[back++] = x;
    }
    int pop()
    {
        --size;
        return q[front++];
    }
};
bool bfs(int s, int t)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    { // Shob gula node k white korlam
        visited[i] = false;
    }
    Queue q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.pop();
        cout << u << " ";
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        } // completely explored
    }
    return false;
}
int fordFulkerson(int s, int t)
{
    int u, v;
    int rGraph[N][N];

    for (u = 0; u < N; u++)
        for (v = 0; v < N; v++)
            rGraph[u][v] = graph[u][v];

    int parent[N];
    int max_flow = 0;
    while (bfs(s, t))
    {

        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}
int main()
{
    // total vertices
    cin >> V;

    for (int i = 0; i < V; i++)
    {
        int u, v;

        cout << "u v" << endl;

        cin >> u >> v;

        int weight; // capacity
        cout << "Enter weight" << endl;
        cin >> weight;
        graph[u][v] = weight;
    }

    cout << "Max flow: " << fordFulkerson(0, V - 1);
}