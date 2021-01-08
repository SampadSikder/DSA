#include<bits/stdc++.h>
#include<string.h>
#include<ctype.h>

#define N 20
char stack[N];
int top=-1;

void push(char x)
{
    if(top==N-1){
        printf("Overflow\n ");
    }
    else {top++;
          stack[top]=x;
    }


}
char pop(){
    if(top==-1){
        printf("Underflow\n");
    }
    else{return stack[top--];
    }
}
int priority(char x){
    if(x=='(')return 0;

    if(x=='+' || x=='-')return 1;

    if(x=='*' || x=='/')return 2;
}

string InfixtoPostfix(String f){
    string exp="";
    int i,j;
    char x;

    for(i=0 ; f[i]!='\0' ; i++){
        //if((f[i]>=48 && f[i]<=57)||(f[i]>=65 && f[i]<=90) || (f[i]>= 97 && f[i]<=122))//checking if f[i] is alphanumeric
        if(isalnum(f[i]))
        {
            j=i;
            while(isalnum(f[j]))//while we encounter another operator we continue printing
                {
                   //printf("%c",f[j]);
                   exp+=f[j];
                    j++;
                }
            //printf(" ");
            exp+=" ";
            i=j-1;
        }
        else if(f[i]=='(')//push opening braces direct into stack
        {
                push(f[i]);
        }
        else if(f[i]==')')
        {
            while((x=pop()) != '(')//keep popping until first bracket is encountered we used x variable so first we can pop ( then move on
            {
                exp+=x;
                //printf("%c ",x);
            }
        }
        else if(f[i]==32){
            continue;
        }
        else
        {
            while(priority(stack[top]) >= priority(f[i])) //if the incoming one is of lower precedence pop the higher precedence until lower precedence is encountered
           {
                //printf("%c ",pop());
                x=pop();
                exp+=x;
            }
            push(f[i]);
        }

    }
    while(top!=-1){
        //printf("%c ",pop());
        x=pop();
        exp+=x;
    }
    return exp;

}







int main(){
    string f,post;
    int i,j;
    char x;
    printf("Enter the function: ");
    gets(f);

    post = InfixtoPostfix(f);






}
