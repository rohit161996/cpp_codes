#include <bits/stdc++.h>
using namespace std;

int maxPro(int index, vector<int>& nums, vector<int> &dp){
    if(index >= nums.size()){
        return 0;
    }

    // If already solved do not solve
    if(dp[index] != -1){
        return dp[index];
    }

    // Include the current value
    int include = nums[index] + maxPro(index+2, nums, dp);

    // Exclude the current value
    int exclude = maxPro(index+1, nums, dp);

    // Take the maximum profit from the include and exclude
    dp[index] = max(include, exclude);
    return dp[index];
}

int rob(vector<int>& nums) {
    int index = 0;
    int n = nums.size();
    vector<int> dp(n+1, -1);
    int max_Profit = maxPro(index, nums, dp);
    return max_Profit;
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout << rob(nums);
    return 0;
}