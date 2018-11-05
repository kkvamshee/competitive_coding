#include <iostream>
using namespace std;
int n;
void show(int A[], int l, int r){
	while(l!=r){
		cout<<A[l++]<<" ";
	}
	cout<<endl;
}
void merge(int arr[], int l, int m, int r)
{
    int i1=l, i2=m+1, re[r-l+1]={0}, k=0;
    while(i1<m+1 && i2<r+1){
        if(arr[i1]<arr[i2]){
            re[k]=arr[i1];
            k++; i1++;
        }
        else{
            re[k]=arr[i2];
            i2++; k++;
    }
    while(i1<m+1){
        re[k] = arr[i1];
        i1++; k++;
    }
    while(i2<r+1){
        re[k]  =arr[i2];
        i2++; k++;
    }
    }
    for(int i=l; i<r+1; i++) arr[i]=re[i-l];
}
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        printf("calling mergesort at %d and %d\n", l, m+1);
        show(arr, l, m+1);
        mergeSort(arr, l, m);
        printf("calling mergesort at %d and %d\n", m+1, r);
        show(arr, m+1, r+1);
        mergeSort(arr, m+1, r);
        printf("merging %d %d %d\n", l, m, r);
        show(arr, l, r+1);
        merge(arr, l, m, r);
    }
}
int main(){
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++) cin>>A[i];
	mergeSort(A, 0, n-1);
	show(A, 0, n);
	return 0;
}
