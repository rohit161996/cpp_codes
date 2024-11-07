#include<bits/stdc++.h>
using namespace std;

int missingNumberBrute(vector<int>& nums){
    // Sort the array
    sort(nums.begin(), nums.end());

    // Match the number with their index
    // If not equal return that index
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(i != nums[i]){
            return i;
        } 
    }
    return n;
}

int missingNumberOptimal(vector<int>& nums) {
    int n = nums.size();
    int xor_num = 0;

    // Calculate sum of total numbers
    for(int i=1; i<=n; i++){
        xor_num = xor_num ^ i;
    }

    // Subtract the numbers from the total sum to get the answer
    for(int i=0; i<n; i++){
        xor_num = xor_num ^ nums[i];
    }

    // Return the answer
    return xor_num;
}

int missingNumber(vector<int>& nums) {
    // Return the optimal
    return missingNumberBrute(nums);
}

int main(){
    vector<int> nums = {0,1,2,4,5,6};

    int ans = missingNumber(nums);
    cout << ans;

    return 0;
}