#include<bits/stdc++.h>
using namespace std;

const int N=5;

int matrix[N][N];

int main(){
    int cost,u,v;

    cin>>u>>v;//u Node v edges


    for(int i=0;i<v;i++){
            int n1,n2;
            cin>>n1>>n2>>cost;
            matrix[n1][n2]=cost;
            matrix[n2][n1]=cost; //undirected graph

    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    }
