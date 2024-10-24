#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int> nums, int index){
    // We have reached beyond the destination or we are struck
    if(index >= nums.size() || nums[index] == 0){
        return false;
    }
    // We have reached the destination
    if(index = nums.size()-1){
        return true;
    }
    int trav = nums[index];
    int ans = false;
    // jump starts from 1 to the number of jumps
    for(int jump = 1; jump <= trav; jump++){
        ans = ans || helper(nums, index+jump);
    }

    return ans;
}

bool canJump(vector<int> &nums){
    int index = 0;
    bool ans = helper(nums, index);
    return ans;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums);
    return 0;
}