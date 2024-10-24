#include <bits/stdc++.h>
using namespace std;

// By iteration
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int mrows = matrix.size();
    int ncols = matrix[0].size();

    // Start from the upper right most corner
    int row = 0;
    int col = ncols-1;
    
    while(row < mrows && col >=0){
        if(matrix[row][col] == target){
            cout << "The element is at row no." << row << " and the column no. is " << col << endl;
            return true;
        }
        else if(matrix[row][col] > target){
            // If the target is lesser than the element
            // move towards the left or decrease the column
            col--;
        }
        else{
            // If the target is greater than the element
            // move downwards or increase the row
            row++;
        }
    }
    return false;
}

// By recursion
bool helper(vector<vector<int>>& matrix, int target, int row, int col, int mrows, int ncols){
    // Base case for termination in recursion
    if(row >= mrows || col < 0){
        return false;
    }

    // Base case if element is find
    int curr_value = matrix[row][col];
    if(curr_value == target){
        return true;
    }
    else if(curr_value > target){
        // If the target is smaller move towards the left
        return helper(matrix, target, row, col-1, mrows, ncols);
    }
    else{
        return helper(matrix, target, row+1, col, mrows, ncols);
    }
}

bool searchMatrixRec(vector<vector<int>>& matrix, int target) {
    // Total rows and total columns
    int mrows = matrix.size();
    int ncols = matrix[0].size();

    // Starting rows and starting columns
    int srow = 0;
    int scol = ncols-1;

    bool ans = helper(matrix, target, srow, scol, mrows, ncols);
    return ans;
}

int main(){
    int target = 11;
    vector<vector<int>> nums {{1,   3,  5,  7},
                              {10, 11, 16, 20},
                              {23, 30, 34, 60}};
    // bool ans = searchMatrix(nums, target);
    // cout << ans << endl;

    bool ans_rec = searchMatrixRec(nums, target);
    cout << ans_rec;
    return 0;
}