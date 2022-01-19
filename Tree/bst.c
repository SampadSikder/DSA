//Input using array
#include<stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};
struct node* root=NULL;

struct node* createNode(int data){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->parent=NULL;

    return newNode;
}

void insert(int data,struct node* currentNode){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(currentNode=NULL){currentNode=createNode(data);
                        currentNode->parent=NULL;
                        root=currentNode;
                    }
    else if(data<=currentNode->data){
        if(currentNode->left!=NULL)insert(data,currentNode->left);
        else{
            newNode=createNode(data);
            newNode->parent=currentNode;
            currentNode->left=newNode;
        }
    }
    else{
        if(currentNode->right!=NULL) insert(data,currentNode->right);
        else{
            newNode=createNode(data);
            newNode->parent=currentNode;
            currentNode->right=newNode;
        }
    }

}
void inorder(struct node *currentNode){
    if(currentNode==NULL)return;
    inorder(currentNode->left);
    printf("%d ",currentNode->data);
    inorder(currentNode->right);

}


int main(){
    int array[10];
    for(int i=0;i<10;i++){array[i]=rand()%100;
                        insert(array[i],array[0]);}
    inorder(root);
    puts("");

    }


