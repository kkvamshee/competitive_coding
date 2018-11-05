#include <iostream>
#include <string>
using namespace std;


/*
#####################################################
#####################################################
		CountAndSay problem from InterviewBit
				Category : Strings
#####################################################
#####################################################

The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.
*/


int slide(string s, int i){
    char t = s[i];
    while(i<s.length() && s[i]==t) i++;
    return i-1;
}
string countAndSay(int A) {
    string s = "1";
    int n=1;
    while(n<A){
        int curr = s.length(), i=0;
        string ns;
        while(i<curr){
            int temp = slide(s, i);
            ns+=char('1'+temp-i);
            ns+=s[i];
            i=temp+1;
        }
        s=ns;
        n++;
    }
    return s;
}
int main(){
	int n;
	cin>>n;
	cout<<CountAndSay(n)<<endl;
	return 0;
}
