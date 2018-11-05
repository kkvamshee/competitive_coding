#include<iostream>
using namespace std;
void show(int A[], int n){
	for(int i=0; i<n; i++) cout<<A[i]<<" ";
	cout<<endl;
}
void CountSort(int A[], int n, int pow){
	int count[10]={0}, re[n];
	for(int i=0; i<n; i++) count[(A[i]/pow)%10]+=1;
	for(int i=1; i<10; i++) count[i] += count[i-1];
	for(int i=n-1; i>=0; i--){
		re[count[(A[i]/pow)%10]-1] = A[i];
		count[(A[i]/pow)%10]--;
	}
	for(int i=0; i<n; i++){
		A[i] = re[i];
	}
}
void RadixSort(int A[], int n, int maxi){
	int nod=1;
	while(maxi){
		maxi/=10;
		nod*=10;
	}
	for(int i=1; i<=nod; i*=10){
		CountSort(A, n, i);
	}
}
int main(){
	int n, maxi=INT_MIN;
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
		maxi = max(A[i], maxi);
	}
	RadixSort(A, n, maxi);
	show(A, n);
	return 0;
}
