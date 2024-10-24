#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    // Base case
    if(n == 1) return nums[n-1];
    
    // Corner cases
    int start = 0;
    int end = n-1;
    if(nums[start] != nums[start+1]) return nums[start];
    if(nums[end] != nums[end-1]) return nums[end];

    int mid = start + ((end-start)/2);
    while(start <= end){
        if((mid-1 >=0 && nums[mid]!=nums[mid-1]) && (mid+1<n && nums[mid]!=nums[mid+1])){
            return nums[mid];
        }
        // (even, odd) -> Left goto right
        // (odd, even) -> right goto left
        // Mid is at odd index and previous element of mid is not same 
        // as mid element, we are at right side so move to left
        if(!(mid&1)){
            // (even, odd) -> Left goto right                
            if(mid+1 < n && nums[mid] == nums[mid+1]){
                start = mid + 1;
            }
            // (odd, even) -> right goto left
            if(mid-1 >= 0 && nums[mid] == nums[mid-1]){
                end = mid - 1;
            }
        }
        else{
            // (odd, even) -> right goto left
            if(mid+1 < n && nums[mid] == nums[mid+1]){
                end = mid - 1;
            }
            // (even, odd) -> Left goto right
            if(mid-1 >= 0 && nums[mid] == nums[mid-1]){
                start = mid + 1;
            }
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main(){
    
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    int ans = singleNonDuplicate(nums);
    cout << "The single element in a duplicate array is "<< ans;
    
    return 0;
}