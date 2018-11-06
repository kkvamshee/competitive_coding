#include<iostream>
using namespace std;
void show(int A[], int n){
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
void BubbleSort(int a[], int n){
	for(int i=0; i<n; i++)
		for(int j=1; j<n-i; j++){
			if(a[j]<a[j-1]) swap(a[j], a[j-1]);
		}
}
int main(){
	int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	BubbleSort(A, 9);
	for(int i=0; i<9; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}
