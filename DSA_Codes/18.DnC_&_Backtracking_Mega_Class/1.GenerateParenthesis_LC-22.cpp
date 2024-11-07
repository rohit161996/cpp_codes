#include<bits/stdc++.h>
using namespace std;

void helper(int n, string &output, vector<string> &ans, int open, int close){
        if(open + close == 2*n){
        ans.push_back(output);
        return;
        }
        
        // Restricted recursion :
        // First open bracket is added to parenthesis (if < n)
        if(open < n){
            output.push_back('(');
            helper(n, output, ans, open+1, close);
            // Backtracking
            output.pop_back();
        }
        
        // Close bracket is added to parenthesis (if < open)
        if(close < open){
            output.push_back(')');
            helper(n, output, ans, open, close+1);
            // Backtracking
            output.pop_back();
        }
}

vector<string> generateParenthesis(int n) {
    string output = "";
    vector<string> ans;
    int open = 0;
    int close = 0;
    helper(n, output, ans, open, close);
    return ans;
}

int main(){
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for(auto it : ans){
        cout << it << endl;
    }
    return 0;
}