#include <stdio.h>
int a[100];
int b[100];

void merge(int arr[], int low, int middle, int high){
    int l = low,r = middle+1,k = low ;

    while(l<=middle && r<=high){
        if(arr[l]<arr[r]) b[k++] = arr[l++];
        else b[k++] = arr[r++];
    }

    if(l>middle){
        while(r<=high){
            b[k++] = arr[r++];
        }
    }
    else{
        while(l<=middle){
            b[k++] = arr[l++];
        }
    }

    for(l=low;l<=high;l++) a[l] = b[l];
}

void merge_sort(int ar[], int lower, int upper){
    int mid;
    if(lower < upper){
        mid = (lower+upper)/2;

        merge_sort(ar, lower, mid);
        merge_sort(ar, mid+1, upper);
        merge(ar, lower, mid, upper);
    }
}

int main()
{
    int n, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    merge_sort(a, 0, n);

    for (i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
}
