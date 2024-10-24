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

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> nums = {1};

    int pivot_index = get_pivot_index(nums);
    cout << "Pivot Index is " << pivot_index;
    
    return 0;
}