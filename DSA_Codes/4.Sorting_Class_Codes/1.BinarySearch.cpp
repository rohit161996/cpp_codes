#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& nums, int target){
    int start = 0;
    int end = nums.size()-1;

    while(start <= end){
        int mid = start + ((end-start)/2);
        if(nums[mid]==target){
            // Return Index
            return mid;
        }
        else if(nums[mid] < target){
            // Move to the right
            start = mid + 1;
        }
        else{
            // Move to the left
            end = mid - 1;
        }
    }
    // Element not found return -1
    return -1;
}

int main(){
    int target = 50;
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int ans = binary_search(arr, target);
    cout << ans;

    return 0;
}