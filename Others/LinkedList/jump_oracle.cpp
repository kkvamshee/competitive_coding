#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int jump(int A[], int n){
	int sum = 0;
	for(int i=0; i<n; i++){
		int P[n];
		for(int j=0; j<n; j++){
			if(j<=i) P[j] = 0;
			else{
				P[j] = INT_MAX;
				for(int k=i; k<j; k++){
					if(k+A[k] >= j) P[j] = min(P[j], 1+P[k]);
				}
				sum+=P[j];
			}
		}
		
		for(int k=0; k<n; k++) cout<<P[k]<<" ";
		cout<<endl;
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i=0; i<n ;i++) cin>>A[i];
	cout<<jump(A, n);
}
