//complete link list
#include<iostream>

struct node{
    int data;
    struct node *next;
    struct node *prev;
    };
struct node *head=NULL;

void InsertatFront(int x){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;

	/*if(head==NULL){
		head=temp;
		temp->next=NULL;
		return;
	}*/
	temp->next=head;
    temp->prev=NULL;

    if(head!=NULL){
        head->prev=temp;
    }
	head=temp;

}

void InsertatBack(int x){
    struct node *temp1,*temp2;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=x;

    if(head==NULL){
       temp1->next=head;
       head=temp1;
       return;
    }
    temp2=head;

    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

void printlist(){
	struct node *temp;
	//temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	if (temp == NULL){
		printf("List Empty\n");
		return;
	}

	while (temp!= NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	//printf("%d ",temp->data);
	puts("");
}


node *searchlist(struct node *temp,int x){
    if(head==NULL){
        printf("List is empty");
        return NULL;
    }
    if(temp==NULL){
            printf("Not found!");
            return NULL;
    }
    if(temp->data==x){
        return temp;
    }
    else return searchlist(temp->next,x);

}
//void delete(int x){
//
//	node *agerta, *current;
//
//	if (head == NULL){
//		printf("List is empty\n");
//		return;
//	}
//	agerta = start;
//
//	while (agerta->next != NULL){
//
//		current = agerta->next;
//		if(current != NULL && current->data == x) break;
//		agerta = agerta->next;
//	}
//	if(agerta->next == NULL){
//		printf("Not found!");
//		return;
//	}
//	agerta->next = current->next;
//	free(current);
//
//}
//}


int main(){//complete link list
#include<iostream>

struct node{
    int data;
    struct node *next;
    };
struct node *head=NULL;

void InsertatFront(int x){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;

	/*if(head==NULL){
		head=temp;
		temp->next=NULL;
		return;
	}*/
	temp->next=head;
	head=temp;

}

void InsertatBack(int x){
    struct node *temp1,*temp2;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=x;

    if(head==NULL){
       temp1->next=head;
       head=temp1;
       return;
    }
    temp2=head;

    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

void printlist(){
	struct node *temp;
	//temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	if (temp == NULL){
		printf("List Empty\n");
		return;
	}

	while (temp!= NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	//printf("%d ",temp->data);
	puts("");
}


node *searchlist(struct node *temp,int x){
    if(head==NULL){
        printf("List is empty");
        return NULL;
    }
    if(temp==NULL){
            printf("Not found!");
            return NULL;
    }
    if(temp->data==x){
        return temp;
    }
    else return searchlist(temp->next,x);

}
void delete(int x){

	node *agerta, *current;

	if (head == NULL){
		printf("List is empty\n");
		return;
	}
	agerta = start;

	while (agerta->next != NULL){

		current = agerta->next;
		if(current != NULL && current->data == x) break;
		agerta = agerta->next;
	}
	if(agerta->next == NULL){
		printf("Not found!");
		return;
	}
	agerta->next = current->next;
	free(current);

}
}


int main(){

	InsertatFront(20);
	printlist();
	InsertatFront(10);
	printlist();
	InsertatFront(30);
	printlist();
	InsertatBack(50);
	printlist();

	node *srch;

	int u=50;
	srch=searchlist(head,u);

    if(srch!=NULL){
        printf("Found %d!\n",u);
    }
    delete(20);
    printlist();//complete link list
#include<iostream>

struct node{
    int data;
    struct node *next;
    };
struct node *head=NULL;

void InsertatFront(int x){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;

	/*if(head==NULL){
		head=temp;
		temp->next=NULL;
		return;
	}*/
	temp->next=head;
	head=temp;

}

void InsertatBack(int x){
    struct node *temp1,*temp2;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=x;

    if(head==NULL){
       temp1->next=head;
       head=temp1;
       return;
    }
    temp2=head;

    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

void printlist(){
	struct node *temp;
	//temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	if (temp == NULL){
		printf("List Empty\n");
		return;
	}

	while (temp!= NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	//printf("%d ",temp->data);
	puts("");
}


node *searchlist(struct node *temp,int x){
    if(head==NULL){
        printf("List is empty");
        return NULL;
    }
    if(temp==NULL){
            printf("Not found!");
            return NULL;
    }
    if(temp->data==x){
        return temp;
    }
    else return searchlist(temp->next,x);

}
void delete(int x){

	node *agerta, *current;

	if (head == NULL){
		printf("List is empty\n");
		return;
	}
	agerta = start;

	while (agerta->next != NULL){

		current = agerta->next;
		if(current != NULL && current->data == x) break;
		agerta = agerta->next;
	}
	if(agerta->next == NULL){
		printf("Not found!");
		return;
	}
	agerta->next = current->next;
	free(current);

}
}


int main(){

	InsertatFront(20);
	printlist();
	InsertatFront(10);
	printlist();
	InsertatFront(30);
	printlist();
	InsertatBack(50);
	printlist();

	node *srch;

	int u=50;
	srch=searchlist(head,u);

    if(srch!=NULL){
        printf("Found %d!\n",u);
    }
    delete(20);
    printlist();
}

}


	InsertatFront(20);
	printlist();
	InsertatFront(10);
	printlist();
	InsertatFront(30);
	printlist();
	InsertatBack(50);
	printlist();

	node *srch;

	int u=50;
	srch=searchlist(head,u);

    if(srch!=NULL){
        printf("Found %d!\n",u);
    }
    delete(20);
    printlist();
}
