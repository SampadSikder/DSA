#include<bits/stdc++.h>
#define MAX 100000
#define N 100
using namespace std;
int arr[N];

int binarysearch(int left,int x,int right){
    int mid=(left+right)/2;

    if(arr[mid]==x)return mid;
    if(arr[mid]>x)return binarysearch(left,x,mid-1);
    else return binarysearch(mid+1,x,right);


}

int main(){
    cout<<"Enter the array: "<<endl;
    for(int i=0;i<N;i++){
        arr[i]=rand()%1000;
    }
    sort(arr,arr+N);

    cout<<"The array is: "<<endl;
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nEnter character to search:"<<endl;
    int x,pos;
    cin>>x;
    pos=binarysearch(0,x,N-1);

    cout<<"Position of element is: "<<pos+1<<endl;
}
