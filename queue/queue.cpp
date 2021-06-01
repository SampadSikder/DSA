#include<bits/stdc++.h>
using namespace std;
int frnt=-1;
int rear=-1;
int arr[100];

bool isEmpty(){
    if(frnt==-1 && rear==-1){return true;}

    else return false;

}

bool isFull(){
    if(rear>100)return true;
    else return false;
}

void Enqueue(int x){
    if(isFull()){
        printf("Overflow\n");
        return;
    }
    else if(isEmpty()){
        frnt=rear=0;
        arr[rear]=x;
        return;
    }
    else rear++;
    arr[rear]=x;
}
void dequeue(){
    if(isEmpty()){
        printf("Underflow\n");
        return;
    }
    printf("Removed element:%d ",arr[frnt]);
    frnt++;
    puts("");

}
void printList(){
    for(int i=frnt;i<=rear;i++){
        printf("%d\n",arr[i]);
    }
}


int main(){
    Enqueue(5);
    Enqueue(6);
    Enqueue(6);
    Enqueue(2);
    printList();
    dequeue();
    printList();


    }
