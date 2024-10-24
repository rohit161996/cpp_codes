#include<bits/stdc++.h>
using namespace std;

/*
 * Problem description :
 * Given an array of numbers which represent the value of items in a house.
 * we need to pick the item such that the value is maximum and no adjacent houses 
 * should be picked.
 * For [10, 20, 30, 40, 50, 60, 70] --> [10, 30, 50, 70]
 * So, the value is 160.
 * 
 * I/P :- [10, 20, 30, 40, 50, 60, 70]
 * O/P :- 160.
 * 
 */

int helper(vector<int> &nums, int index){
    if(index >= nums.size()){
        return 0;
    }

    // Pick the number in the array
    int includeAns = nums[index] + helper(nums, index+2);

    // Do not pick the number in the array
    int excludeAns = helper(nums, index+1);

    return max(includeAns , excludeAns);
}

int rob(vector<int>& nums) {
    int index = 0;
    int n = nums.size();
    int ans = helper(nums, index);
    return ans;
}

int main(){
    vector<int> nums = {10, 20, 30, 40, 50, 60, 70};
    int ans = rob(nums);
    cout << ans;
    return 0;
}  