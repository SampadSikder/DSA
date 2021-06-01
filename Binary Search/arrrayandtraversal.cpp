#include<bits/stdc++.h>
using namespace std;
const int N=100;

int arr[N]={0};
int inorder[N];
int preorder[N];
int postorder[N];
int top1=0,top2=0,top3=0,type,nodes;

//Simulating a type of stack
void push(int x){
    if(type==1){
        preorder[top1++]=x;
    }
    else if(type==2){
        inorder[top2++]=x;
    }
    else if(type==3){
        postorder[top3++]=x;
    }
}

void preorder_func(int index){
    //type define for push and checking index
    type=1;
    if(index>=nodes)return;
    if(arr[index]==-1)return;

    //push and recursive call
    push(arr[index]);
    preorder_func(2*index+1);
    preorder_func(2*index+2);

}
void inorder_func(int index){
    type=2;
    if(index>=nodes)return;
    if(arr[index]==-1)return;

    //push and recursive call
    inorder_func(2*index+1);
    push(arr[index]);
    inorder_func(2*index+2);
}
void postorder_func(int index){
    type=3;
    if(index>=nodes)return;
    if(arr[index]==-1)return;

    //push and recursive call
    postorder_func(2*index+1);
    postorder_func(2*index+2);
    push(arr[index]);
    }



int main(){
    printf("How many nodes?: ");
    cin>>nodes;
    //Input array
    for(int i=0;i<nodes;i++){
            cin>>arr[i];
            if(arr[i]==-1){nodes++;}
    }

    //Memory representation
    printf("Memory representation: ");
    for(int i=0;i<nodes;i++){
        if(arr[i]==-1){printf("- ");}
        else printf("%d ",arr[i]);
    }
    puts("");



    int index=0;
    //Traversal
    preorder_func(index);
    //Preorder print
    printf("Preorder traversal: ");
    for(int i=0;i<top1;i++){
        printf("%d ",preorder[i]);
    }
    puts("");

    //Inorder
    inorder_func(index);
    //Inorder print
    printf("Inorder traversal: ");
    for(int i=0;i<top2;i++){
        printf("%d ",inorder[i]);
    }
    puts("");

    //postorder
    postorder_func(index);
    //postorder print
    printf("Postorder traversal: ");
    for(int i=0;i<top3;i++){
        printf("%d ",postorder[i]);
    }
    puts("");



}
