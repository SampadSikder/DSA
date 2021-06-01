#include<bits/stdc++.h>
using namespace std;
int main(){
    int cost,N;
    cout<<"Enter number of nodes: ";
    cin>>N;

    int matrix[N][N];


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("Enter cost at position %d %d: ",i,j);
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
