#include<bits/stdc++.h>
using namespace std;
int a[100];

void MaxHeapify(int index,int len){

    int large=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<len && a[left]>a[index]){
        large=left;
    }
    if(right<len && a[right]>a[large]){
        large=right;
    }
    if(large!=index){
        swap(a[index],a[large]);
        MaxHeapify(large,len);
    }
}

//void BuildMinHeap(int len){
//    int i;
//    for(i=len/2;i>=0;i--){
//        MinHeapify(i,len);
//    }
//
//}

void print(int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void HeapSort(int len){
    for(int i=len/2-1; i>=0; i--){
        MaxHeapify(i,len);
    }
    for(int i=len-1;i>0;i--){
        swap(a[0],a[i]);
        MaxHeapify(0,i);
    }

}

int main(){
    int len,eof=-1;

//    len=sizeof(a)/sizeof(a[0]);
    cout<<"Enter the elements"<<endl;

    for(int i=0;i<100;i++){
        cin>>a[i];
        if(a[i]==-1){
            len=i;
            break;
        }
    }

    HeapSort(len);
    //ans=1 2 3 4 7 9 10 14 8 16
    print(len);

}
