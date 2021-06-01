#include<bits/stdc++.h>
using namespace std;

const int N=10000;
vector<int>adj[N];
int main(){
    int nodes,edges;

    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
    }

    for(int i=1;i<=nodes;i++){
            if(adj[i].size()!=0){
                int cnt=0;
                cout<<i<<"----";
                for(int j=0;j<adj[i].size();j++){
                    cout<<adj[i][j]<<" ";
                    cnt++;

            }
            cout<<"Connected with node "<<i<<": "<<cnt;

        }
        cout<<endl;
    }


}
