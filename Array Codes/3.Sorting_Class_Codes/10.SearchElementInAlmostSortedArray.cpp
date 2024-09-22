#include <bits/stdc++.h>
using namespace std;

int getElementInSortedArray(vector<int> nums, int target){
    int n = nums.size();

    int start = 0;
    int end = n-1;

    int ans = -1;
    int mid = start + ((end-start)/2);
    while(start <= end){
        // If element is at mid return mid
        if(nums[mid] == target)
        {
            return mid;
        }
        // If element is at mid+1 return mid+1
        else if(nums[mid+1] == target)
        {
            return mid+1;
        }
        // If element is at mid-1 return mid-1
        else if(nums[mid-1] == target){
            return mid-1;
        }
        // If target is greater than mid element
        else if(nums[mid] < target){
            // Move to the right
            start = mid + 2;
        }
        // If target is less than mid element
        else if(nums[mid] > target){
            // Move to the left
            end = mid - 2;
        }
        mid = start + ((end-start)/2);       
    }
    return ans;
}

int main(){
    // Make a nearly sorted array
    vector<int> nums = {10, 3, 40, 20, 50, 80, 70};

    // the element
    int element = 50;

    // call the function to get element from nearly sorted array
    int ans = getElementInSortedArray(nums, element);
    cout << "The element is at "<< ans << "th Index";
    
    return 0;
}
