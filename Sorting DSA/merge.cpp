#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
int a[N],tmplist[N] ;

void merge(int lpos, int rpos, int rightend){
	int leftend=rpos-1;

	int tmppos=lpos;

	int left_index=lpos;
	int right_index=rightend;

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
		lpos++;
	}
	while(rpos<=rightend){
		tmplist[tmppos]=a[rpos];
		tmppos++;
		rpos++;
	}
	for (int i=left_index;i<=right_index;i++){
		a[i] = tmplist[i];
	}
}


void msort(int x, int Left, int Right){
	if(Left < Right){
		int Center=(Left+Right)/2;

		msort(x , Left , Center);

		msort(x ,Center+1 , Right);


		merge(Left, Center+1, Right);
	}
}



int main(){
	int n;
	cin>>n;
	for(int i=0; i<n ;i++)a[i]=rand()%1000;

	cout<<"Unsorted array:\n";

	for(int i=0;i<n;i++)cout<<a[i]<<" ";

    cout<<"\n";


	msort(n, 0, n-1);


	cout<<"sorted array:\n";

	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
