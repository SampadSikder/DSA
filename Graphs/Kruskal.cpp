#include <bits/stdc++.h>
// using namespace std;
const int N = 100;
struct graph
{
    int u;
    int v;
    int w;
} weighted_graph[N];
int parent[N];
void make_set(int n)
{
    parent[n] = n;
}
int find_set(int n)
{
    if (parent[n] == n)
        return n;
    return find_set(parent[n]);
}
void Union(int a, int b)
{
    int parent_a = find_set(a);
    int parent_b = find_set(b);
    if (parent_a != parent_b)
    {
        parent[parent_b] = parent_a;
    }
}
int main()
{
    int nodes, edges;
    std::cout << "enter the number of nodes and edges: " << std::endl;
    std::cin >> nodes >> edges;
    std::cout << "Enter graph: ";
    int n1, n2;
    for (int i = 0; i < edges; i++)
    {
        std::cin >> n1 >> n2 >> weighted_graph[i].w;
        weighted_graph[i].u = n1;
        weighted_graph[i].v = n2;
    }
    for (int i = 0; i < nodes; i++)
    {
        make_set(i);
    }

    std::sort(weighted_graph, weighted_graph + edges, [](graph a, graph b)
              { return a.w <= b.w; });

    for (int i = 0; i < edges; i++)
    {
        if (find_set(weighted_graph[i].u) != find_set(weighted_graph[i].v))
        {
            Union(weighted_graph[i].u, weighted_graph[i].v);
            std::cout << (char)(weighted_graph[i].u + 97 + 1) << " " << (char)(weighted_graph[i].v + 97 + 1) << std::endl;
        }
    }
    for (int i = 1; i < nodes; i++)
    {
        std::cout << "Parent of i: " << (char)(i + 96) << ": " << (char)(parent[i] + 96) << std::endl;
    }
}