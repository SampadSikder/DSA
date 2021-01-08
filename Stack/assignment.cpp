#include<bits/stdc++.h>
#include <math.h>
#define N 20
using namespace std;
char stck[N];
double intstack[N];
int top=-1, inttop=-1;


void int_push(int x){
    if(inttop==N-1){
        cout<<"Overflow\n"<<endl;

    }
    else {
        inttop++;
        intstack[inttop]=x;
    }


}


double int_pop(){
    if(inttop==-1)cout<<"Underflow"<<endl;

    else return intstack[inttop--];

}


void char_push(char x)
{
    if(top==N-1){
        printf("Overflow\n ");
    }
    else {top++;
          stck[top]=x;
    }
}


char char_pop(){
    if(top==-1){
        printf("Underflow\n");
    }
    else{return stck[top--];
    }
}


//Convert string to number
int strtonum(string x){
    int sum = 0;
    int j=0;

    for(int i=x.size()-1;i>=0;i--){
        sum+=(x[i]-'0')*pow(10,x.size()-1-i);//number is multiplied by its place value then added

    }
    return sum;
}



int priority(char x){
    if(x=='(')return 0;

    if(x=='+' || x=='-')return 1;

    if(x=='*' || x=='/')return 2;
}


string InfixtoPostfix(string f){
    int i,j;
    string exp;
    char x;

    for(i=0 ; i<f.size() ; i++){
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
            exp+=' ';
            i=j-1;
        }
        else if(f[i]=='(')//push opening braces direct into stck
        {
                char_push(f[i]);
        }
        else if(f[i]==')')
        {
            while((x=char_pop()) != '(')//keep popping until first bracket is encountered we used x variable so first we can pop ( then move on
            {
                exp+=x;
                //exp+=' ';
                //printf("%c ",x);
            }
        }
        else if(f[i]==32){
            continue;
        }
        else
        {
            while(priority(stck[top]) >= priority(f[i])) //if the incoming one is of lower precedence pop the higher precedence until lower precedence is encountered
           {
                //printf("%c ",pop());
                x=char_pop();
                exp+=x;
                exp+=' ';
            }
            char_push(f[i]);
        }

    }
    while(top!=-1){
        //printf("%c ",pop());
        x=char_pop();
        exp+=x;
        exp+=' ';

    }
    cout<<"Postfix expression is: "<<endl;
    cout<<exp<<endl;
    return exp;

}


void evaluate(string post){
    int i,j;
    char ch;
    string x,num;
    double val=0,a,b;

    for(i=0;i<post.size();i++){
        //ch=post[i];

        if(isalnum(post[i])){//if ch is operand directly push into stack
            //Inside if
            num+=post[i];
            i++;

            while(isalnum(post[i]))
                {
                num+=post[i];
                i++;
                }
            i--;

            int_push(strtonum(num));

            num.clear();//empty string
        }

        else if(post[i]==' '){
            //cout<<"Inside else if"<<endl;
            continue;
        }
         else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/')
        {

            a = int_pop();
            b = int_pop();

            ch=post[i];

            switch(ch){
            case '+':
                int_push(b+a);
                break;
            case '-':
                int_push(b-a);
                break;

            case '*':
                int_push(b*a);
                break;
            case '/':
                int_push(b/a);
                break;
            default:break;

        }
    }
    }

   cout<<"Value:"<<intstack[inttop]<<endl;



}


int main(){
    char inf[N];
    string f,post;
    int i,j;
    char x;

    printf("Enter the function: ");
    gets(inf);

    for(i=0; i<strlen(inf) ; i++){
        f+=inf[i];
    }

    post=InfixtoPostfix(f);

    evaluate(post);

}
