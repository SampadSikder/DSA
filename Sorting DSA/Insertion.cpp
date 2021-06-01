//Insertion sort
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;

    cin>>n;

    int i,temp,j,a[n];

    for(i=0;i<n;i++){

        a[i]=rand()%100;
    }

    //sorting

    for(i=1;i<n;i++){

        temp=a[i];

        j=i-1;

        while(j>=0 && a[j]>temp){

            a[j+1]=a[j];

            j--;
        }

        a[j+1]=temp;
    }

    for(i=0;i<n;i++)cout<<a[i]<<endl;
}
