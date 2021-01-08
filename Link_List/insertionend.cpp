#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;//To create node pointer in c we write struct node*, in c++ only node* is enough
};
struct node* head=NULL;

//insertion at end
void Insertatback(int x){
    struct node* temp;
    temp=(node*)malloc(sizeof(node));
    temp -> data=x;


    //insert a value
    if(head==NULL){
        temp->next=NULL;
        temp=head;
        return;
    }
    //travel at end and establish link
    struct node* temp1=head;
    while((temp1 -> next)!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
    temp->next=NULL;
}

void print(){
    struct node* temp=head;
    cout<<"list is:" <<endl;
    while(temp != NULL){
        cout<< temp -> data <<" "<<endl;
        temp= temp -> next;
        }

}



int main(){
    //empty list
    cout<<"How many numbers?"<<endl;
    int n,i,x;

    cin>>n;

    cout<<"Enter numbers:"<<endl;
    for(i=0;i<n;i++){
        cin>>x;
        Insert(x);

    }

    print();


}
