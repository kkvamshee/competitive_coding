#include <iostream>
using namespace std;
void swap(int* x, int* y){
    int temp=*x;
    *x = *y;
    *y = temp;
}
void show(int A[], int n){
    for(int i=0; i<n; i++) cout<<A[i]<<" ";
    cout<<endl;
}
int partition(int A[], int low, int high){
    int pi = high;
    int i=low;
    for(int j=low; j<high; j++){
        if (A[j]<A[pi]){
        	swap(A+i, A+j);
        	i++;
		}
    }
    swap(&A[i], &A[high]);
    return i;
}
void Qsort(int A[], int low, int high){
    if(low<high){
        int pi = partition(A, low, high);
        Qsort(A, low, pi-1);
        Qsort(A, pi+1, high);}
}

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++) cin>>A[i];
        Qsort(A, 0, n-1);
        show(A, n-1);
    }
	return 0;
}

