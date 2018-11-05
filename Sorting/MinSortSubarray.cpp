#include <iostream>
using namespace std;
void MinSortSubarray(int A[], int n){
    if(n==1) {cout<<0<<" "<<0<<endl; return;}
    int l=0, r=n-1, maxi=-1000, mini=1000;
    
    while(l<n && A[l]<A[l+1]) l++;
    while(r>=0 && A[r-1]<A[r]) r--;
    for(int i=l; i<=r; i++){
        mini = min(mini, A[i]);
        maxi = max(maxi, A[i]);
    }
    l=0; r=n-1;
    while(l<n && A[l]<mini) l++;
    while(r>=0 && A[r]>maxi) r--;
    cout<<l<<" "<<r<<endl;
}
int main() {
	//code
	int t, n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int A[n];
	    for(int i=0; i<n; i++) cin>>A[i];
	    MinSortSubarray(A, n);
	}
	return 0;
}
