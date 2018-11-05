#include<iostream>
using namespace std;

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
