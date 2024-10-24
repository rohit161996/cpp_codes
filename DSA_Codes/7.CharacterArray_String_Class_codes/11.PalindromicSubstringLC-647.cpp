#include<bits/stdc++.h>
using namespace std;

int countTotal(string s, int start, int end, vector<string>& ans){
    int count = 0;
    while( start >=0 && end < s.length() && s[end] == s[start] ){
        ans.push_back(s.substr(start, end-start+1));
        count++;
        start--;
        end++;
    }
    return count;
}

void countSubstrings(string s) {
    int totalPalindrome = 0;
    vector<string> ans;
    for(int center=0; center<s.length(); center++){
        // Odd length
        int i = center;
        int j = center;
        int oddPalindrome = countTotal(s, i, j, ans);

        // Even Length
        i = center;
        j = center + 1;
        int evenPalindrome = countTotal(s, i, j, ans);

        totalPalindrome = totalPalindrome + oddPalindrome + evenPalindrome;
    }
    cout << totalPalindrome << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
}

int main(){
    string arr = "abca";
    cout << " The string is "<< arr << endl;
    countSubstrings(arr);
    return 0;
}