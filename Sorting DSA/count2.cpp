#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N],cnt[N];

void print(int n){
	for (int i=0;i<n;i++){
		printf(" %5d ",a[i]);
	}
	puts("");
}

int main () {

	int n;
	scanf("%d",&n);

	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) cnt[a[i]]++;

	printf("array before sorting: ");
	print(n);

	int x=0;

	for (int i=0;i<N;i++){ // N is a constant, means what the range of the entire array is
		if (cnt[i]) {
			for (int j=0;j<cnt[i];j++){
				a[x++] = i;
			}
		}
	}
	printf("array after sorting :");
	print(n);
}
