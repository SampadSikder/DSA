//Insertion and deletion at end
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;//To create node pointer in c we write struct node*, in c++ only node* is enough
};
struct node* head;
void Insert(int data,int n){

    node* temp1=(node*)malloc(sizeof(node));
    temp1->data=data;
    temp1->next=NULL;

    //If first element
    if(n==1){
        temp1->next=head;
        head=temp1;
        return;
    }

    node* temp2=head;

    //going to the n-1th term 0 to n-2 means traversing n-1times
    for(int i=0;i<n-2;i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next= temp1;

}

void Delete(int n){
    struct node* temp1;
    int i;
    if(n==1){
        head=temp1->next;//head now points to second
        free(temp1);
        return;
    }

    for(i=0;i<n-2;i++)
        temp1=temp1->next;
        //temp1 points to n-1th node
    struct node* temp2 = temp1->next;//nth node
    temp1->next = temp2 -> next;//n+1th node
    free(temp2);//delete temp2
}
void Print(){
    struct node* temp=head;
    cout<<"list is:" <<endl;
    while(temp != NULL){
        cout<< temp -> data <<" "<<endl;
        temp= temp -> next;
        }

}


int main(){
    head=NULL;

    Insert(2,1);//2
    Insert(3,2);//2,3
    Insert(4,3);//2,3,4
    Insert(5,2);//2,5,3,4
    Insert(7,3);//2,5,7,3,4

    Delete(2);
    Print();


}
