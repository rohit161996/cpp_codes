#include <bits/stdc++.h>
using namespace std;

// Time complexity is O(n^2)
// Space Complexity is O(1)
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int ans = -1;
    for(int i=0; i<n; i++){
        int left_sum = 0;
        int right_sum = 0;
        // Calculate left sum
        for(int j=i-1; j>=0; j--){
            left_sum = left_sum + nums[j];
        }

        // Calculate right sum
        for(int k=i+1; k<n; k++){
            right_sum = right_sum + nums[k];
        }
        
        // Check if sum is equal 
        if(left_sum == right_sum){
            ans = i;
            break;
        }
    }
    return ans;
}

// Time complexity is O(n)
// Space Complexity is O(n)
int pivotIndexOptimal(vector<int>& nums) {
    int ans = -1;
    int n = nums.size();

    int leftSum[n];
    int rightSum[n];

    // Calulate left sum of the array
    // and store it in the array
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + nums[i];
        leftSum[i] = nums[i] + sum;
    }

    // Calulate right sum of the array
    // and store it in the array
    sum = 0;
    for(int j=n-1; j>=0; j--){
        sum = sum + nums[j];
        rightSum[j] = nums[j] + sum;
    }

    // Check for the index where right and left sum are equal
    for(int k=0; k<n; k++){
        if(leftSum[k] == rightSum[k]){
            ans = k;
            break;
        }
    }

    return ans;
}

// Time complexity is O(n)
// Space Complexity is O(n)
int pivotIndexOptimalProper(vector<int>& nums) {
    int ans = -1;
    int n = nums.size();

    vector<int> leftSum(nums.size(),0);
    vector<int> rightSum(nums.size(),0);

    // Calulate left sum of the array
    // and store it in the array
    for(int i=1; i<n; i++){
        leftSum[i] = leftSum[i-1] + nums[i-1];
    }

    // Calulate right sum of the array
    // and store it in the array
    for(int j=n-2; j>=0; j--){
        rightSum[j] = rightSum[j+1] + nums[j+1];
    }

    // Check for the index where right and left sum are equal
    for(int k=0; k<n; k++){
        if(leftSum[k] == rightSum[k]){
            ans = k;
            break;
        }
    }

    return ans;
}

int main(){

    vector<int> nums = {-1,1,1,-1,1};

    int ans = pivotIndexOptimalProper(nums);
    cout << ans;

    return 0;
}