#include<bits/stdc++.h>
using namespace std;

/* Problem Description:
 * Given a natural number we have to find combinations from them
 * taking k numbers at a time
 * 
 * I/P :- n = 4, k = 2, from 1,2,3,4 take two at a time and form 
 * O/P :- [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]].
 * 
 * If in the given code we will call index+1 instead of i+1 we will 
 * get combination of k numbers with repetition.
 *
 */

void helper(int n, int k, vector<vector<int>> &ans, vector<int> &output, int index, int count){
    // Base Case counter
    if(count == k){
        ans.push_back(output);
        return;
    }

    for(int i=index; i<=n; i++){
        output.push_back(i);
        helper(n, k, ans, output, i+1, count+1);
        // Backtracking
        output.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 1;
    int count = 0;
    helper(n, k, ans, output, index, count);
    return ans;
}

int main(){
    vector<vector<int>> ans = combine(4,2);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}