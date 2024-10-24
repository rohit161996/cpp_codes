#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& mat, int row, int sum, int &target){
    // If the row size reaches the end get absolute difference and return
    if(row == mat.size()){
        int absoluteDiff = abs(target-sum);
        return absoluteDiff;
    }
    int ans = INT_MAX;
    for(int col=0; col<mat[row].size(); col++){
        // for all the elements in the row add the element with the sum 
        int recAns = helper(mat, row+1, sum+mat[row][col], target);
        ans = min(ans, recAns);
    }
    return ans;
}

int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    int sum = 0, row = 0;
    return helper(mat, row, sum, target);
}

int main(){
    vector<vector<int>> mat {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}
                            };
    int target = 13;
    cout << minimizeTheDifference(mat, target);
    return 0;
}
