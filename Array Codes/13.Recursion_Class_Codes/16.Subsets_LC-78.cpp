#include<bits/stdc++.h>
using namespace std;

/*
 * Problem description :
 * Given an array of numbers, we need to find all subsets.
 * For [10, 20, 30] --> [[], [10], [20], [30], [10, 20], [20, 30], [10, 30], [10, 20, 30]]
 * So, there are total 8 subsets.
 * 
 * I/P :- [10, 20, 30]
 * O/P :- [[], [10], [20], [30], [10, 20], [20, 30], [10, 30], [10, 20, 30]]
 * 
 */

void helper(vector<int>& nums, int index, vector<vector<int>> &ans, vector<int> temp){
    int size = nums.size();
    // Base case
    if(index == size){
        ans.push_back(temp);
        return;
    }

    // Pick the number
    temp.push_back(nums[index]);
    helper(nums, index+1, ans, temp);
    temp.pop_back();

    // Do not pick the number
    helper(nums, index+1, ans, temp);
}

vector<vector<int>> subsets(vector<int>& nums) {
    int index = 0;
    vector<vector<int>> ans;
    vector<int> temp;
    helper(nums, index, ans, temp);
    return ans;
}

int main(){
    vector<int> nums = {10, 20, 30};
    vector<vector<int>> ans = subsets(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans.size();
    return 0;
}