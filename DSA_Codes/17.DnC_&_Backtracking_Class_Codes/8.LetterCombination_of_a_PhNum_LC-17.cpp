#include<bits/stdc++.h>
using namespace std;

void helper(vector<string> &ans, unordered_map<char, string> &map, int index, string output, string digits){
    if(index >= digits.length()){
        if(output.length()>0){
            ans.push_back(output);
        }
        return;
    }
    char digit = digits[index];
    string mapp = map[digit];
    for(int i=0; i<mapp.length(); i++){
        output.push_back(mapp[i]);
        helper(ans, map, index+1, output, digits);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits){
    vector<string> ans;
    unordered_map<char, string> map;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";

    int index = 0;
    string output;
    helper(ans, map, index, output, digits);
    return ans;
}

int main(){
    string digits = "22";
    vector<string> ans = letterCombination(digits);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}