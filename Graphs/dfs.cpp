#include <bits/stdc++.h>
using namespace std;
#define N 100
#define WHITE 1
#define GREY 2
#define BLACK 3
#define NIL -1
#define INF 1e8 + 5

int graph[N + 1][N + 1];
int prevv[N + 1];
int color[N + 1];
int f[N + 1];
int t=0;
int d[N + 1] = {-1};
int node;

void DFS_Visit(int u){
    color[u] = GREY;
    t = t + 1;
    d[u] = t;

    for(int v=0; v<node; v++){

        if(graph[u][v]==1 && color[v]==GREY){
             cout <<"<-- BACK EDGE: " << "U: " << u << " V: " << v << endl;
             cout << "Cycle Exists" << endl;
        }

        if(graph[u][v]==1 && color[v]==BLACK){
            if(d[u]<d[v])
            cout <<"--> FORWARD EDGE: " << "U: " << u << " V: " << v << endl;

            else if(d[u]>d[v])
            cout <<"X CROSS EDGE: " << "U: " << u << " V: " << v << endl;

        }


        if(graph[u][v]==1 && color[v]==WHITE){
            prevv[v] = u;
            cout <<"TREE EDGE: " <<"U= " << u << " V= " << v << endl;
            DFS_Visit(v);
        }
    }

    color[u] = BLACK;
    t += 1;
    f[u] = t;
}

void DFS(){

    for(int u=0; u<node; u++){
        color[u] = WHITE;
        prevv[u]= -1;
        f[u] = 0;
        d[u] = 0;
    }

    t = 1;
    for(int u=0; u<node; u++){

        if(color[u] == WHITE){
            cout << "\nSOURCE: " << u << endl;
            DFS_Visit(u);
        }
    }

}


int main()
{
    cout<<"enter no of nodes: "<<endl;
    int nodes;
    cin>>nodes;

    while(1){//input
        int u,v;
        cin>>u>>v;

        if(u==-1 && v==-1)break;

        graph[u][v]=1;
        //graph[v][u]=1;
    }

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }

    DFS();

}
