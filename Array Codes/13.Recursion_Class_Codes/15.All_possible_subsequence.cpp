#include<bits/stdc++.h>
using namespace std;

/*
 * Problem description :
 * Given a string "abc", we need to find the number of all possible subsequences.
 * For "abc" -> {"", "a", "b", "c", "ab", "ac", "bc", "abc"}
 * So, there are total 8 subsequences.
 * 
 * I/P :- "abc"
 * O/P :- ["", "a", "b", "c", "ab", "ac", "bc", "abc"]
 */

void subsequences(string str, int ind, vector<string>& ans, string output){
    if(ind == str.length()){
        ans.push_back(output);
        return;
    }

    // Solve 1 case
    char letter = str[ind];
    
    // pick the letter
    string picked = output + letter;
    subsequences(str, ind+1, ans, picked);

    // do not pick the letter
    string not_picked = output;
    subsequences(str, ind+1, ans, not_picked);
}

int main(){
    // Subsequence of the following string
    string str = "abc";

    // Answer vector having subsequences
    vector<string> ans;

    // starting of the subsequence index
    int index = 0;

    // output string storing the current subsequence
    string output = "";

    subsequences(str, index, ans, output);
    for(string it : ans){
        cout << it << endl;
    }
    return 0;
}
