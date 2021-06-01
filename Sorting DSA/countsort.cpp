#include<bits/stdc++.h>
using namespace std;

const int N=5;
int a[N];

int main(){
    int k=0;
    for(int i=0; i<N; i++) {a[i]=rand()%100;
                            if(a[i]>k){
                                k=a[i];
                            }
    }
    cout<<"Before sorting"<<endl;
    for(int i=0; i<N; i++)cout<<a[i]<<" ";

    //for(int i=0; i<N; i++){k=max(a[i],k);}

    int b[N],c[k+1];
    //memset(c, 0, k);

    for(int j=0 ; j<N; j++){
        c[a[j]]++;
    }
    for(int i=1; i<k ;i++){
        c[i]+=c[i-1];
    }

    for(int j=N-1; j>=0 ;j--){
            b[c[a[j]]]= a[j];
            c[a[j]]--;
    }
    cout<<"\n";
    for(int i=0; i<N; i++)cout<<b[i]<<" ";

    return 0;


}
