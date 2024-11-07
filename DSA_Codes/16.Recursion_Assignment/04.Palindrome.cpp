#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end){
    if(start >= end){
        return true;
    }

    // Solving 1 case
    if(s[start] != s[end]){
        return false;
    }

    // Solving other cases by recursion
    isPalindrome(s, start+1, end-1);
}

int main(){
    string s = "racecar";
    int start = 0;
    int end = s.size()-1;
    cout << isPalindrome(s, start, end);
    return 0;
}