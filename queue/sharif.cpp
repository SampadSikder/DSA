#include<bits/stdc++.h>
using namespace std;
#define N 3

int frontt = -1, rear = -1, queueee[N];

bool checkIfFull()
{
    if(rear == N-1)
    {
        return true;
    }
return false;
}

bool checkIfEmpty()
{
    if(rear == -1 && frontt == -1)
    {
        return true;
    }
return false;
}

void enqueue(int x)
{
    if(checkIfFull())
    {
        printf("Overflow!\n");
        return;
    }

    else if(checkIfEmpty())
    {
        frontt++;
        rear++;
        queueee[rear] = x;
    }

    else
    {
        rear++;
        queueee[rear] == x;
    }
}

void dequeue()
{
    if(checkIfEmpty())
    {
        printf("Underflow!\n");
        return;
    }

    //else if(frontt == rear) frontt = rear = -1;
    else
    {
        printf("Deleted %d\n",queueee[frontt]);
        frontt++;
    }
}

void peek()
{
    if(checkIfEmpty())  printf("Underflow!\n");
    else                printf("The data at front is %d \n",queueee[frontt]);
}

void display()
{
    if(checkIfEmpty()) printf("Underflow!\n");
    else
    {

        int i,j=0;
        for(i=frontt; i<=rear+1; i++)
        {
            printf("%dth element is %d \n",j+1,queueee[frontt]);
            j++;
        }

    }
}
int main()
{
    enqueue(420);
    enqueue(11);
    enqueue(121);
    display();
    dequeue();
    peek();
    display();
}
