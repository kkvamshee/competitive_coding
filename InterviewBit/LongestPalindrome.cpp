#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
#####################################################
#####################################################
		CountAndSay problem from InterviewBit
				Category : Strings
#####################################################
#####################################################



Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"

*/
string longestPalindrome(string A) {
    string S = "#";
    for(int i=0; i<A.length(); i++){
        S+=A[i];
        S+="#";
    }
    
    int n = S.length();
    vector<int> lps(n, 0);
    lps[0]=0;
    lps[1]=1;
    int center=1, right_end=2, left_end=0;
    
    for(int current=2; current<n; current++){
        int mirror = 2*center-current;
        lps[current]=min(lps[mirror], right_end-current);
        if(current+lps[current] >= right_end){
            center=current;
            right_end=current+lps[current];
            left_end=2*current-right_end;
            while(left_end>0 && right_end<n-1 && S[left_end]==S[right_end]){
                left_end--;
                right_end++;
            }
            if(S[left_end]!=S[right_end]){
                left_end++;
                right_end--;
            }
            lps[current]=right_end-current;
        }
        cout<<current<<" "<<center<<" "<<left_end<<" "<<right_end<<" ";
        string temp(S.begin()+left_end, S.begin()+right_end);
        cout<<temp<<" ";
        temp.assign(S.begin()+current-lps[current], S.begin()+current+lps[current]);
        cout<<temp<<endl;
    }
    
    center = max_element(lps.begin(), lps.end())-lps.begin();
    string re="";
    for(int i=center-lps[center]; i<=center+lps[center]; i++){
        if(S[i]!='#') re+=S[i];
    }
    return re;
}

int main(){
	string S;
	cin>>S;
	cout<<longestPalindrome(S)<<endl;
	return 0;
}
