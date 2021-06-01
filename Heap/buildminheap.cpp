#include<bits/stdc++.h>
using namespace std;
int a[100];

void MinHeapify(int index,int len){

    int smol=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<len && a[left]<a[index]){
        smol=left;
    }
    if(right<len && a[right]<a[smol]){
        smol=right;
    }
    if(smol!=index){
        swap(a[index],a[smol]);
        MinHeapify(smol,len);
    }
}
void BuildMinHeap(int len){
    int i;
    for(i=len/2;i>=0;i--){
        MinHeapify(i,len);
    }

}

void print(int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int len;
//    len=sizeof(a)/sizeof(a[0]);
    cout<<"Enter number of elements: ";
    cin>>len;
    cout<<"Enter the elements dynamically:"<<endl;
    for(int i=0;i<len;i++){
        cin>>a[i];
//        if(a[i]=='F'&&a[i-1]=='O'&&a[i-2]=='E'){
//                len=i-2;
//                break;
//        }
    }
    //ans=1 2 3 4 7 9 10 14 8 16
    BuildMinHeap(len);
    print(len);


}
