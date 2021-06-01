#include<bits/stdc++.h>
using namespace std;
int a[100];

void print(int len){
    for(int i=1;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void InsertHeap(int data,int index){
    a[index]=data;
    int i=index;

    //Insert new element
    while(i>=0){
        int parent=i/2;
        if(a[parent]>a[i]){
            swap(a[parent],a[i]);
            i=parent;
        }
        else{
            return;
        }

    }
}

int main(){
    a[0]=NULL;

    int data,len=1;

//    freopen("input.txt","r",stdin);

    cout<<"Enter data: "<<endl;

    while(cin>>data){
        InsertHeap(data,len);
        len++;
    }
    print(len);


}
