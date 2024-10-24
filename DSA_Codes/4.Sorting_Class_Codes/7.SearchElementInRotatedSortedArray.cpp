#include <bits/stdc++.h>
using namespace std;


int get_pivot_index(vector<int>& nums){
    int start = 0;
    int end = nums.size()-1;
    int ans = 0;
    int mid = start + ((end-start)/2);
    while(start <= end){

        // If there is only one element return its index
        if(start == end){
            return start;
        }

        // If current element is greater than next 
        // return it 
        if(nums[mid] > nums[mid+1]){
            return mid;
        }

        // We are on Line B
        if(nums[start] > nums[mid]){
            end = mid - 1;
        }

        // We are on Line A
        else{
            start = mid + 1;
        }

        //Update mid
        mid = start + ((end-start)/2);
    }
    return ans;
}

int binary_search(vector<int>& nums, int start, int end, int target){
    int s = start;
    int e = end;
    while(s <= e){
        int m = s + ((e-s)/2);
        if(nums[m] == target){
            return m;
        }
        else if(nums[m] > target){
            e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return -1;
}

int main(){
    int ans = 0;
    int target = 0;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int pivot_index = get_pivot_index(nums);
    if(target >= nums[0] && target <= nums[pivot_index]){
        ans = binary_search(nums, 0, pivot_index, target);
    }
    else{
        ans = binary_search(nums, pivot_index+1, nums.size()-1, target);
    }
    cout << ans;
    return 0;
}