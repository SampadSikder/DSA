#include<bits/stdc++.h>
using namespace std;
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define INF 1e8+5
typedef long long ll;
typedef unsigned long long ull;


int graph[N][N];
int color[N];
int prevv[N];
int d[N];

struct Queue{
    int q[N+N];
    int front;
    int back;

    int size;

    Queue(){
        front=0;
        back=0;
        size=0;
    }
    bool empty(){
        return size==0;
    }
    void push(int x){
        q[back++]=x;
    }
    int pop(){
        --size;
        return q[front++];
    }
};

void bfs(int source){
    for(int i=0;i<N;i++){//Shob gula node k white korlam
        color[i]=WHITE;
        prevv[i]=NIL;
        d[i]=0;
    }
    color[source] = GRAY;
    d[source] = 0;
    prevv[source] = NIL;

    Queue q;
    q.push(source);

    while(!q.empty()){
        int u=q.pop();

        for(int v=0;v<N;v++){
            if(graph[u][v]==1){
                if(color[v]==WHITE){
                    color[v]=GRAY;//already explored
                    d[v]=d[u]+1;
                    prevv[v]=u;

                    q.push(v);//push v into stack
                }
            }
        }
        color[u]=BLACK;//completely explored
    }

}

int main(){
    cout<<"enter no of nodes: "<<endl;
    int nodes;
    cin>>nodes;

    while(1){//input
        int u,v;
        cin>>u>>v;

        if(u==-1 && v==-1)break;

        graph[u][v]=1;
        graph[v][u]=1;
    }

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }

    cout<<"Enter source: ";

    int source;
    cin>>source;
    bfs(source);

    for(int i=0;i<nodes;i++){
        cout<<"distance from source:"<<endl;
        cout<<"d["<<i<<"]="<<d[i]<<endl;
    }
}
