//Generate tree from preorder and inorder
#include<bits/stdc++.h>
using namespace std;
const int N=100;

int tree[N];
int preorder[N];
int postorder[N];
int inorder[N];
int total=-1;
int preorder_index=0;

void maxx(int &a,int b){
    a=max(a,b);
    }

void buildtree_preorder(int start,int last,int tree_index,int array_length){

    //If we cross last node
    if(start > last)return;


    if(preorder_index>=array_length)return;

    //Traverse traversal
    int root=preorder[preorder_index];
    preorder_index++;

    tree[tree_index]=root;
    maxx(total,tree_index);
    //At the last node
    if(start==last){
        //tree[tree_index]=root;
        return;
    }
    int i;

    //Search for current node in inorder
    for(i=start;i<=last;i++){
        if(root==inorder[i])break;
    }

    //Recursive call

    buildtree_preorder(start,i-1,2*tree_index,array_length);
    buildtree_preorder(i+1,last,2*tree_index+1,array_length);

    return;
}
int main(){

    freopen("input.txt","r",stdin);
    int nodes,level;
    printf("Enter number of nodes: ");
    scanf("%d",&nodes);

    memset(tree,-1,sizeof(tree));

    //or(int i=1; i<=pow(2,level)-1; i++) cout<<tree[i]<<" ";
    cout<<"Enter preorder: ";
    for(int i=0;i<nodes;i++)cin>>preorder[i];

    cout<<"\nEnter inorder: ";
    for(int i=0;i<nodes;i++)cin>>inorder[i];

    //int start=0;

    //tree[start]='\0';

    buildtree_preorder(0,nodes-1,1,nodes);


    for(int i=1; i<=total; i++) {
            if(tree[i]==-1)cout<<"Blank ";
            else cout<<tree[i]<<" ";
    }

}
