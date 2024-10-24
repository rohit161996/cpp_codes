#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &nums, int target, int index){
    // Base case
    if(target == 0)
        return true;

    if(target < 0 || index >= nums.size())
        return false;

    // Pick the element
    bool picked = helper(nums, target-nums[index], index+1);

    // Do not pick the element
    bool not_picked = helper(nums, target, index+1);

    return (picked || not_picked);
}

bool canPartition(vector<int>& nums) {
    // 1. If sum is odd we cannot divide the array
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum&1) return false;

    // 2. Make a [target = sum/2] and find subarray using recursion i.e. include/exclude
    int target = sum >> 1;
    return helper(nums, target, 0);
}

int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);
    return 0;
}