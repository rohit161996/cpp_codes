#include <bits/stdc++.h>
using namespace std;

bool isMatchHelper(string &s, int si, string &p, int pi, vector<vector<int>> &dp){
    // Return values from dp table
    if(dp[si][pi] != -1){
        return dp[si][pi];
    }

    // Base case - Both the strings are exhausted
    if(si == s.size() && pi == p.size()){
        return dp[si][pi] = true;
    }

    // String p is exhausted and s is remaining
    if(si < s.size() && pi == p.size()){
        return dp[si][pi] = false;
    }

    // String s is exhausted and p is remaining with *
    if(si == s.size() && pi < p.size()){
        while(pi < p.size()){
            if(p[pi] != '*') return dp[si][pi] = false;
            pi++;
        }
        return dp[si][pi] = true;
    }

    // Solving 1 case
    // Single character matching
    if(s[si] == p[pi] || p[pi] == '?'){
        return dp[si][pi] = isMatchHelper(s, si+1, p, pi+1, dp);
    }

    // if p's index points to *
    if(p[pi] == '*'){
        // Case 1: Consider "*" as ""
        bool case1 = isMatchHelper(s, si, p, pi+1, dp);

        // Case 2: Consider * has consumed 1 character
        bool case2 = isMatchHelper(s, si+1, p, pi, dp);

        return dp[si][pi] = (case1 || case2);
    }

    // Character does not match from both the strings
    return dp[si][pi] = false;
}

bool isMatch(string s, string p) {
    int si = 0; // index for s string
    int pi = 0; // index for p string

    // Since 2 arguments are changing so a 2D array is considered for DP
    vector<vector<int>> dp(s.size()+1, vector<int> (p.size()+1, -1));

    return isMatchHelper(s, si, p, pi, dp);
}

int main(){
    string s = "adcdeffg";
    string p = "abc*fg";
    cout << isMatch(s, p);
    return 0;
}