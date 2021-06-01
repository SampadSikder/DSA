#include<bits/stdc++.h>
using namespace std;

const int N = 10000;
int a[N],tmplist[N] ;

void merge(int lpos, int rpos, int rightend){
	int leftend=rpos-1;

	int tmppos=lpos;

	int numelement=rightend-lpos+1;

	while(lpos<=leftend && rpos<=rightend){
		if(a[lpos]<=a[rpos]){
			tmplist[tmppos]= a[lpos];
			tmppos++;
			lpos++;
		}
		else{
			tmplist[tmppos]= a[rpos];
			tmppos++;
			rpos++;
		}
	}
	while(lpos<=leftend){
		tmplist[tmppos]=a[lpos];
		tmppos++;
		rpos++;
	}
	while(rpos<=rightend){
		tmplist[tmppos]=a[rpos];
		tmppos++;
		rpos++;
	}


void msort(int size, int Left, int Right){
	if(Left < Right){
		int Center=(Left+Right)/2;
		msort(N , Left , Center);
		msort(N ,Center+1 , Right);

		merge(Left, Center+1, Right);
	}
}



int main(){
	int n;
	cin>>n
	for(int i=0; i<n ;i++)a[i]=rand()%1000;

	cout<<"Unsorted array:\n";

	for(int i=0;i<n;i++)cout<<a[i];

	endl;

	msort(a , n, 0, n-1);

	cout<<"sorted array:\n"

	for(int i=0;i<n;i++)cout<<a[i];
}
