#include<bits/stdc++.h>
using namespace std;

// If we will pass the temporary vector by reference it will give the answer wrong
void helper(vector<int> nums, vector<vector<int>> &ans, 
            int index, vector<int> temp){
    // If the index reaches the end store the array to answer
    if(index == nums.size()){
        ans.push_back(temp);
        return;
    }
    // for each value in the array swap it with the next elements 
    // to create the permutations
    for(int j=index; j<temp.size(); j++){
        swap(temp[index], temp[j]);

        // do this task recursively
        helper(nums, ans, index+1, temp);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    // Creating the answer vector
    vector<vector<int>> ans;

    // Temporary vector to store the given vector
    vector<int> temp;
    for(int i=0; i<nums.size(); i++){
        temp.push_back(nums[i]);
    }
    // Helper function to store the answer to the vector
    helper(nums, ans, 0, temp);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}