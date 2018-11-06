#include<iostream>
using namespace std;
int n;
void show(int A[], int n){
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
void insert(int arr[], int i)
{
    int j=i, temp=arr[j];
    while(j>0 && temp<arr[j-1]){
    	arr[j] = arr[j-1];
    	j--;
	}
    arr[j] = temp;
    show(arr, n);
}
void insertionSort(int arr[], int n)
{
   for(int i=1; i<n; i++) insert(arr, i);
}

int main(){
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++) cin>>A[i];
	insertionSort(A, n);
	show(A, n);
	return 0;
}
