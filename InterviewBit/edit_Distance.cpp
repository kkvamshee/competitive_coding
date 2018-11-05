#include <bits/stdc++.h>
using namespace std;
int edit(string a, string b, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
    	cout<<"i="<<i<<endl;
        for(int j=0; j<=n; j++){
            if(i==0 || j==0) dp[i][j] = i+j;
            else if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
            cout<<i<<a[i]<<"\t"<<b[j]<<j<<"\t"<<dp[i][j]<<endl;
        }
    }
    return dp[m][n];
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int m=4,n=5;
	    string a="geek",b="gesek";
	    cout<<edit(a, b, m, n)<<endl;
	}
	return 0;
}
