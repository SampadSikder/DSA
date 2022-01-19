#include<bits/stdc++.h>
using namespace std;
const int N=100;

int tree[N];
int preorder[N];
int postorder[N];
int inorder[N];

void buildtree_postorder(int start,int last, int *postorder_index,int tree_index){

    //If we cross last node
    if(start > last || *postorder_index<0)return;

    //Traverse traversal
    int cur=postorder[*postorder_index];
    (*postorder_index)--;


    //At the last node
    if(start==last){
        tree[tree_index]=cur;
        return;
    }
    int i;

    //Search for current node in inorder
    for(i=start;i<=last;i++){
        if(cur==inorder[i])break;
    }

    //Recursive call

    buildtree_postorder(i+1,last,postorder_index,2*tree_index+1);
    buildtree_postorder(start,i-1,postorder_index,2*tree_index);

    tree[tree_index]=cur;
    return;
}





int main(){
    int nodes,level;
    printf("Enter number of nodes and level: ");
    scanf("%d %d",&nodes,&level);

    memset(tree,-1,sizeof(tree));

    //or(int i=1; i<=pow(2,level)-1; i++) cout<<tree[i]<<" ";
    cout<<"Enter postorder: ";
    for(int i=0;i<nodes;i++)cin>>postorder[i];

    cout<<"\nEnter inorder: ";
    for(int i=0;i<nodes;i++)cin>>inorder[i];

    int postorder_index=nodes-1;

    //tree[postorder_index]='\0';

    buildtree_postorder(0,postorder_index,&postorder_index,1);

    //Output
    for(int i=1; i<=pow(2,level)-1; i++) {
            if(tree[i]==-1)cout<<"Blank ";
            else cout<<tree[i]<<" ";
    }

}
