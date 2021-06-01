#include<bits/stdc++.h>
using namespace std;

const int N = 10000;
int a[N] ;

void print (int size){

	for (int i=0;i<size;i++){
		printf("%5d ", a[i] );
	}
	puts("");
}

void sort (int size) {

	int key ;
	int cnt = 0 ;
	for (int i = 1; i<size ; i++){
		printf(" # %d\n", ++cnt);
		print(size);
		key = a[i] ;
		int j = i - 1; // compare with this lot
		//while ( j >= 0 and a[j] > key ) {
		for ( ; j>=0 && a[j] > key; j--){
			printf("  key index = %d , key value = %d , current index = %d, current value = %d\n",i,key,j,a[j]);
			a [ j + 1 ] = a[j];
			printf(" ");
			print(size);
			//j--;
		}
		a[j+1] = key;
	}
}

void selection_sort(int size){
	int cnt = 0;
	for (int i=0;i<size-1;i++){

		if ( cnt == 0) print(size);
		printf("# %d \n",++cnt);
		int min_index = i;

		for (int j = i + 1 ;j < size ;j++){

			if ( a[j] < a[min_index] and j < size) {
				min_index = j;
			}
		}
		printf("prev min index = %d , current min index = %d \n",i,min_index);
		printf("before the change : " );
		print(size);
		swap (a[i],a[min_index]);
		printf("after the change  : ");
		print(size);

	}
}

int main (){
	int n;
	scanf("%d",&n);

	mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

	for (int i=0;i<n;i++){
		a[i] = rng() % 10000;
	}

	sort (n);

	printf("FINAL\n");
}
