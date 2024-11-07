#include<bits/stdc++.h>
using namespace std;

pair<int, int> binarySearch_return_values(vector<vector<int>> &nums, int target, int mrows, int ncols, int start, int end){
    // Termination condition
    if(start > end){
        return {-1,-1};
    }

    // Find mid index and set its row and column index to (mid / ncols, mid % ncols)
    int mid = start + ((end-start)/2);
    int current = nums[mid/ncols][mid%ncols];
    // If the element is found return true
    if(current == target){
        return {mid/ncols, mid%ncols};
    }
    else if(current > target){
        // Go to the left
        return binarySearch_return_values(nums, target, mrows, ncols, start, mid-1);
    }
    else{
        // Go to the right
        return binarySearch_return_values(nums, target, mrows, ncols, mid+1, end);
    }
}

bool binarySearch(vector<vector<int>> &nums, int target, int mrows, int ncols, int start, int end){
    // Termination condition
    if(start > end){
        return false;
    }

    // Find mid index and set its row and column index to (mid / ncols, mid % ncols)
    int mid = start + ((end-start)/2);
    int current = nums[mid/ncols][mid%ncols];
    // If the element is found return true
    if(current == target){
        return true;
    }
    else if(current > target){
        // Go to the left
        return binarySearch(nums, target, mrows, ncols, start, mid-1);
    }
    else{
        // Go to the right
        return binarySearch(nums, target, mrows, ncols, mid+1, end);
    }
}

bool search(vector<vector<int>> &nums, int target){
    // Row and column size
    int mrows = nums.size();
    int ncols = nums[0].size();

    // Starting and ending index
    int start = 0;
    int end = mrows * ncols - 1;

    // Search in 2D Matrix using Binary Search
    bool ans = binarySearch(nums, target, mrows, ncols, start, end);

    pair<int, int> ans_pair = binarySearch_return_values(nums, target, mrows, ncols, start, end);
    cout << "The element is present at row no: " << ans_pair.first << " and column no: " << ans_pair.second; 

    return ans;
}

int main(){
    vector<vector<int>> nums {{1,   3,  5,  7},
                              {10, 11, 16, 20},
                              {23, 30, 34, 60},};
    int target = 34;
    int index = search(nums, target);
    return 0;
}