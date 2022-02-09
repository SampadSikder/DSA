#include <bits/stdc++.h>
using namespace std;
struct graph
{
    int weight;
    int node1;
    int node2;
};
struct we_ed graph[N];
int main()
{
    int node, edge;

    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        cin >> w >> u >> v;
        graph[i].weight = w;
        graph[i].node1 = u;
        graph[i].node2 = v;
    }
    // sort
    sort(graph.weight, graph.weight + edge);
}