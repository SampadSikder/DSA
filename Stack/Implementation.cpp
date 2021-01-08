#include<bits/stdc++.h>
#define N 5
using namespace std;

int stck[N];
int top=-1;

void push(int x){

    if(top>=N-1){
        cout<<"Overflow"<<endl;
    }
    else{
        top++;
        stck[top]=x;
    }

}
void printstack(){
    int i;
    for(i=top;i>=0;i--){
        cout<<stck[i]<<" ";
    }
    puts("\n");
}
void pop(){
    int item;
    if(top==-1)cout<<"Underflow"<<endl;
    else{
        item=stck[top];
        top--;
    }
    cout<<"Popped item is "<<item<<endl;
}
void peek(){
    if(top==-1)cout<<"Underflow"<<endl;

    else{
        cout<<"Top element is: "<<stck[top]<<endl;
    }
}

int main(){
    cout<<"Enter 5 data"<<endl;
    int x;
    //Fill the stack
    for(int i=0;i<N;i++){
        cin>>x;
        push(x);
    }
    printstack();
    //Popping one;
    pop();
    printstack();

    push(6);
    printstack();

    push(7);
    printstack();

    pop();
    printstack();

    peek();

}
