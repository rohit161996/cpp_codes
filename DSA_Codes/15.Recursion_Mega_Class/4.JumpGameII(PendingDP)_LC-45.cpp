#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> nums, int index, int steps){
    if(index == nums.size()-1){
        return steps;
    }
    if(index >= nums.size() || nums[index] == 0){
        return INT_MAX;
    }

    int ans = INT_MAX;
    for(int jump=1; jump<=nums[index]; jump++){
        // Solving 1 case and rest of the cases by recursion
        ans = min(ans, helper(nums, index+jump, steps+1));
    }
    return ans;
}

int jump(vector<int>& nums) {
    int index = 0;
    int steps = 0;
    int ans = helper(nums, index, steps);
    return ans;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    int ans = jump(nums);
    cout << ans;
    return 0;
}