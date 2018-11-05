#include <iostream>
using namespace std;
int func(int A[], int sum, int n){
    int before=0, after=sum-A[0];
    if(n==1) return 1;
    for(int i=1; i<n; i++){
    	printf("%d %d", before, after);
        if(before==after) return i;
        before+=A[i-1];
        after=sum-before-A[i];
    }
    return -1;
}

int main() {
	int t,n;
	cin>>t;
	for(int _=0; _<t; _++){
	    cin>>n;
	    int A[n], sum=0;
	    for(int i=0; i<n; i++){
	        cin>>A[i];
	        sum+=A[i];
	    }
	    int res = func(A, sum, n);
	    cout<<res<<endl;
	}
	return 0;
}
