#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
##############################################################
##############################################################
						Fun Jump
##############################################################
##############################################################
Stuart is funny and he likes to jump a lot. There are N boxes
in a line numbered 1 to N. Each box has a value A[i] > i which
represents that from box i Stuart can jump to any box till i+A[i]
A[N]=0
P[i][j] is the minimum number of jumps needed to reach from box i
to box j.
X[i] is the sum of P[i][j] such that i<=j<=N.
Find the sum of X[i] for 1<=i<=N.
*/




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
