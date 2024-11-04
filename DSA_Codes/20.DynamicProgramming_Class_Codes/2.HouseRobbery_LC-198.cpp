#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int index){

    if(index >= nums.size()){
        return 0;
    }

    // Pick the current element
    int pickedAns = nums[index] + helper(nums, index+2);

    // Do not pick the current element
    int notPickedAns = helper(nums, index+1);

    return max(pickedAns, notPickedAns);
}

// Top Down Approach
int dp_helper(vector<int> &dp, vector<int> &nums, int index){
    if(index >= nums.size()){
        return 0;
    }

    // Step 6. Add the base case of already stored answer
    if(dp[index] != -1){
        return dp[index];
    }

    // Pick the current element
    int pickedAns = nums[index] + dp_helper(dp, nums, index+2);

    // Do not pick the current element
    int notPickedAns = dp_helper(dp, nums, index+1);

    // Step 4. Store the answer in the dp array 
    dp[index] = max(pickedAns, notPickedAns);

    // Step 5. Return the answer
    return dp[index];
}

// Bottom Up Approach
int dp_helper_bup(vector<int> &nums, int index){
    // Step 1. Create a dp array
    int n = nums.size();
    vector<int> dp(n+2, 0);

    // Step 2. Base case analysis
    dp[n] = 0;

    // Step 3. Loop in reverse Since in the above case loop was for 0 -> n
    for(int i=n; i>=0; i--){
        // Same logic as top down
        int include = nums[i] + dp[i+2];
        int exclude = 0 + dp[i+1];

        dp[i] = max(include, exclude);
    }

    return dp[0];
}

int rob(vector<int>& nums) {
    int index = 0;
    // int ans = helper(nums, index);

    // Step 1. Create a 1D/2D/3D array based on the number of parameters changing
    // Since only one parameter is changing so use 1D dp
    int n = nums.size();
    vector<int> dp(n+1, -1);

    // Step 2. pass it to the function call
    int ans = dp_helper(dp, nums, index);

    return ans;
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout << rob(nums);
    return 0;
}