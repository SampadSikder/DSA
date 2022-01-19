#include<bits/stdc++.h>

struct Node{
    int data;
    Node* left;
    Node* right;
};


struct Node* createNewNode(int data){
    Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

Node* Insert(Node* root,int data){
    if(root==NULL){//if empty
        root = createNewNode(data);
    }
    else if(data <= root->data){//if less
        root->left = Insert(root->left,data);
    }
    else{//greater
        root->right = Insert(root->right,data);
    }
    return root;


}
struct Node* Delete(struct Node* root, int data){
    if(root==NULL) return root;
    else if(data<root->data)root->left = Delete(root->left,data);
    else if(data>root->data)root->right = Delete(root->right,data);
    else{//found
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
            return root;
        }
        else if(root->left==NULL){
            struct Node *temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL){
            struct Node *temp=root;
            root = root ->left;
            free(temp);
        }
        else {
            struct Node *temp = FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    struct Node* root=NULL;
    int a[10]={10,3,50,55,32,99,44,38,94,100};
    for(int i=0;i<10;i++){
        root=Insert(root,a[i]);
    }
    inorder(root);
//    root=Insert(root,10);
//    root=Insert(root,300);
//    root=Insert(root,6);
//    root=Insert(root,3);

    root=Delete(root,50);
    printf("\nAfter deletion: ");
    inorder(root);
    root=Delete(root,94);
    inorder(root);

}




