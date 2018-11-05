#include <iostream>
using namespace std;

void func(int A[], int n, int req){
    int sum=0, start=0, end=0;
    while(end<=n && sum<req){
    	printf("sum, start, end = %d, %d, %d\n", sum, start, end);
        if(sum<req){
            sum+=A[end++];
        }
        else if(sum>req){
            sum-=A[start++];
        }
        else if(sum==req){
            printf("%d %d", start, end);
        }
    }
}

int main() {
	int t, n, req, x;
	cin>>t;
	for(int _=0; _<t; _++){
	    cin>>n>>req;
	    int A[n];
	    for(int i=0; i<n; i++){
	        cin>>A[i];
	    }
	    func(A, n, req);
	}
	return 0;
}
