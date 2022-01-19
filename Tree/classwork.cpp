#include<stdio.h>

void subTree(int start, int end, int tree_index);
//global
int tree_output[1000], inorder_input[100], postorder_input[1000], postorder_index;
int arraySize;
int x=-1;

int max(int a, int b){
    return (a>b)?a:b;
}

int main(){
    for(int i=1; i<1000; i++) tree_output[i]=-1;

    printf("Array size:");
    scanf("%d",&arraySize);

    printf("Inorder input: ");
    for(int i=0; i<arraySize; i++){
        scanf("%d",&inorder_input[i]);
    }

    printf("postOrder input: ");
    for(int i=0; i<arraySize; i++){
        scanf("%d",&postorder_input[i]);
    }

    postorder_index=arraySize-1;
    subTree(0, arraySize-1, 1);

    for(int i=1; i<=x; i++) printf("%d ",tree_output[i]);
return 0;
}

void subTree(int start, int end, int tree_index){
    if(start>end) return;
    if(postorder_index>0) return;

    int root = postorder_input[postorder_index];
    postorder_index--;
    tree_output[tree_index]=root;
    x=max(x,tree_index);
    if(start==end) return;

    int i;
    for(i=start; i<=end; i++){
        if(inorder_input[i]==root) break;
    }

 //confusion
    subTree(i+1, end, 2*tree_index+1);
    subTree(start, i-1, 2*tree_index);


}
