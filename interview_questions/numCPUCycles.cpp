#include<iostream>
using namespace std;

/*
You have four integers n,d,c1,c2. Consider a hypothetical computer
which can perform only two types of operations: (on a given integer x)
O1 : Subtract 1 from x. This operation costs c1 CPU cycles.
O2 : Divide x by d. Can be performed only if x is divisible by d. This operation costs c2 CPU cycles.
What is the minimum number of cycles in which the computer can reduce the input integer from n to 1.
*/

int numCPUCycles(int n, int d, int c1, int c2) {
    int cost=0;
    while(n>1){
        if(n%d==0){
            if( c2 <= c1*(n-n/d) ){
                n/=d;
                cost+=c2;
            }
            else{
                cost+=c1*(n-1);
                n=1;
            }
        }
        else{
            cost+=c1*(n%d);
            n-=n%d;
        }
    }
    return cost;
}

int main(){
	int n,d,c1,c2;
	cin>>n>>d>>c1>>c2;
	cout<<numCPUCycles(n,d,c1,c2)<<endl;
	return 0;
}
