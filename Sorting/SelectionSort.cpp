#include<iostream>
using namespace std;

void show(int A[], int n){
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int FindMinIndex(int A[], int n){
	int minimum=INT_MAX, idx=-1;
	for(int i=0; i<n; i++){
		if(A[i]<minimum){
			minimum = A[i];
			idx = i;
		}
	}
	return idx;
}

void SelectionSort(int A[], int n){
	for(int i=0; i<n; i++){
		int temp, least=FindMinIndex(A+i, n-i);
		temp = A[i];
		A[i] = A[least+i];
		A[least+i] = temp;
	}
}

int main(){
	int A[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	show(A, 10);
	SelectionSort(A, 10);
	show(A, 10);
	return 0;
}
