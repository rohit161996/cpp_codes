#include <bits/stdc++.h>
using namespace std;

double max_subarray_sum_brute_force(vector<int>& nums, int k){
    double ans,sum;

    int start = 0;
    int n = nums.size();
    while(start < n-k+1){
        // Calculate the sum for i=start till next k numbers.
        for(int i=start; i<start+k; i++){
            sum += nums[i];
        }
        // If sum is greater than answer then update answer.
        if(sum > ans){
            ans = sum;
        }
        cout << "Sum " << sum << endl;
        sum = 0;
        start++;
    }

    return ans/k;
}

// Sliding Window Method 
double max_subarray_sum(vector<int> nums, int k){
    int start = 0;
    int end = 0;

    double ans = INT_MIN;
    double curr_sum = 0;
    while(end < k){
        curr_sum = curr_sum + nums[end];
        end++;
    }

    ans = curr_sum;
    while(end < nums.size()){
        curr_sum = curr_sum - nums[start] + nums[end];
        start++;
        end++;
    }

    return ans/k;
}

int main(){
    int k = 4;
    vector<int> nums = {1,12,-5,-6,50,3};

    double ans = max_subarray_sum_brute_force(nums, k);
    cout << ans;
    
    return 0;
}