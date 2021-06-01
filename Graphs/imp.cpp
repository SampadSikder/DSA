#include<bits/stdc++.h>
using namespace std;

const int N=2;

int matrix[N][N];

int main(){
    int cost;


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("Enter cost at position %d %d",i,j);
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
