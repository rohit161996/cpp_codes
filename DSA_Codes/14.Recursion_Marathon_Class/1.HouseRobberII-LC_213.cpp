#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int index, int size){
    if(index > size){
        return 0;
    }
    // Pick the number in the array
    int includeAns = nums[index] + helper(nums, index+2, size);
    // Do not pick the number in the array
    int excludeAns = helper(nums, index+1, size);
    return max(includeAns , excludeAns);
}

int rob(vector<int>& nums) {
    // Handling the edge case
    int size = nums.size();
    if (size == 1){
        return nums[0];
    }
    int index = 0;
    int ansOne = helper(nums, 0, size-2);
    int ansTwo = helper(nums, 1, size-1);
    int ans = max(ansOne, ansTwo);
    return ans;
}

int main(){
    vector<int> nums = {2,3,2};
    cout << rob(nums);
    return 0;
}