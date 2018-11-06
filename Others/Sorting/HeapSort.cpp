#include<iostream>
using namespace std;
int n;
void show(int A[], int n){
	for(int i=0; i<n; i++) cout<<A[i]<<" ";
	cout<<endl;
}
void heapify(int A[], int n, int i){
	show(A, n);
	int l=2*i+1, r=2*i+2, largest=i;
	if(l<n && A[l]>A[i]) largest=l;
	if(r<n && A[r]>A[largest]) largest=r;
	
	if(largest!=i){
		swap(A[i], A[largest]);
		heapify(A, n, largest);
	}	
}
void HeapSort(int A[], int n){
	for(int i=n/2-1; i>=0; i--) heapify(A, n, i);
	for(int i=n-1; i>=0; i--){
		show(A, n);
		swap(A[0], A[i]);
		heapify(A, i, 0);
	}
	
}

int main(){
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++) cin>>A[i];
	HeapSort(A, n);
	show(A, n);
	return 0;
}
