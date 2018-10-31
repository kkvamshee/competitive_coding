#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class SuperStack{
    public:
    stack<int> S;
    vector<pair<int, int> > aux;
    int n=0;
    
    void push(int x){
        S.push(x);
        aux.push_back(make_pair(0, 0));
        cout<<"pushing "<<x<<" completed \n";
        n++;
    }
    
    void pop(){
        S.pop();
        int e = aux.back().first;
        int x = aux.back().second;
        aux.pop_back();
        this->inc(e-1, x);
        
        cout<<"popped top element \n";
        n--;
    }
    
    int top(){
        cout<<S.top() + aux.back().second<<endl;
        return S.top() + aux.back().second;
    }
    
    void inc(int e, int x){
        return this->inc(aux.end()-1, e, x);
    }
    void inc(vector<pair<int, int> >::iterator it, int e, int x){
        if(e==0 || x==0) return;
        
        int et = it->first;
        int xt = it->second;
        
        it->second += x;
        
        if(et==0){
        	it->first = e;
        	it->second = x;
        	return;
		}
        
        if(e==et) return;
        
        if(e<et){
            it->first = e;
            this->inc(it-(e), et-e, xt);
            return;
        }
        
        if(e>et) this->inc(it-(et), e-et, x);
        return;
    }
    
    int size() return n;
};

int main(){
    SuperStack S;
    S.push(3);
    S.push(5);
    S.push(8);
    S.top();
    S.push(3);
    S.inc(2, 7);
    S.top();
    S.push(10);
    S.push(15);
    S.push(50);
    S.push(1);
    S.top();
    S.inc(3, 10);
    S.inc(5, 12);
    S.push(13);
    S.inc(8, 100);
    
    /*
    for(int i=0; i<S.size(); i++){
        S.top();
        S.pop();
    }
    */
    
    return 0;
}
