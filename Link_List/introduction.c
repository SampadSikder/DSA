#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head=NULL;
    struct node *link;
    struct node *temp;

    struct node *one;
    struct node *two;
    struct node *three;



    int n,i;
    scanf("%d",&n);

    for(i=0;i<n;i++){
            if(i==0){
                    temp=(struct node*)malloc(sizeof(struct node));

                    int info;

                    scanf("%d",&info);

                    temp->data=info;
                    temp->next=NULL;


                    head=temp;
                    link=head;
                    //printf("I am in if\n");
            }
            else{
                    temp=(struct node*)malloc(sizeof(struct node));

                    int info;

                    scanf("%d",&info);

                    temp->data=info;
                    temp->next=NULL;
                    head->next=temp;

                    head=temp;
                //printf("I am in else\n");
            }
    }

    struct node *temp1=link;

    while(temp1!=NULL){
        printf("%d ",temp1 -> data,temp1->next);
        temp1=temp1->next;
    }
}
