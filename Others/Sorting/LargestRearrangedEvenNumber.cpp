#include<iostream>
#include<string>
using namespace std;
void show(string n){
	for(int i=0; i<n.size(); i++) cout<<n[i];
	cout<<endl;
}
void CountSort(string n){
	int count[10]={0}, evemin=300;
	for(string::reverse_iterator it=n.rbegin(); it!=n.rend(); ++it){
		int temp = int(*it);
		count[temp-48]+=1;
		if(temp%2==0) evemin = min(temp, evemin); 
	}
	if(evemin!=300) count[evemin-48]-=1;
	for(int i=9; i>=0; i--){
		for(int j=count[i]; j>0; j--) cout<<i;
	}
	if(evemin!=10) cout<<evemin-48;
	cout<<endl;
}
int main(){
	int t;
	string n;
	cin>>t;
	while(t--){
		cin>>n;
		CountSort(n);
	}
	return 0;
}
