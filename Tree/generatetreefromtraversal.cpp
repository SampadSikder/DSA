#include<bits/stdc++.h>
using namespace std;
const int N=100;

int tree[N];
int preorder[N];
int postorder[N];
int inorder[N];

void buildtree_preorder(int root,int last, int *preorder_index,int tree_index,int array_length){

    //If we cross last node
    if(root > last || *preorder_index>=array_length)return;

    //Traverse traversal
    int cur=preorder[*preorder_index];
    (*preorder_index)++;


    //At the last node
    if(root==last){
        tree[tree_index]=cur;
        return;
    }
    int i;

    //Search for current node in inorder
    for(i=root;i<=last;i++){
        if(cur==inorder[i])break;
    }

    //Recursive call

    buildtree_preorder(root,i-1,preorder_index,2*tree_index,array_length);
    buildtree_preorder(i+1,last,preorder_index,2*tree_index+1,array_length);

    tree[tree_index]=cur;
    return;
}
int main(){

    int nodes,level;
    printf("Enter number of nodes and level: ");
    scanf("%d %d",&nodes,&level);

    memset(tree,-1,N);

    //or(int i=1; i<=pow(2,level)-1; i++) cout<<tree[i]<<" ";
    cout<<"Enter preorder: ";
    for(int i=0;i<nodes;i++)cin>>preorder[i];

    cout<<"\nEnter inorder: ";
    for(int i=0;i<nodes;i++)cin>>inorder[i];

    int root=0;

    tree[root]='\0';

    buildtree_preorder(0,nodes-1,&root,1,nodes);

    cout<<"-1 means that node is empty\nOutput tree: ";
    for(int i=1; i<=pow(2,level)-1; i++) cout<<tree[i]<<" ";


}
