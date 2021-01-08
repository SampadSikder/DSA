//Traversal and insertion
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;//To create node pointer in c we write struct node*, in c++ only node* is enough
};
struct node* head; //Next head is pointer to node

//insertion at beginning
void Insert(int x){
    struct node* temp;
    temp=(node*)malloc(sizeof(node));//Creating dynamic memory allocation in c malloc returns empty places pointer
    //temp=new node();Same thing can only be used in c++

    temp -> data=x;
    temp -> next = head;/*temp -> next = NULL;
                            if(head != NULL)temp -> next=head;*/
    head = temp;
}



void print()
{
    struct node* temp=head;
    cout<<"list is:" <<endl;
    while(temp != NULL){
        cout<< temp -> data <<" "<<endl;
        temp= temp -> next;
        }

}

int main(){
    head=NULL; //empty list
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
