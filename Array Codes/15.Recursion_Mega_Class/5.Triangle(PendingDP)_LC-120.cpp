#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& triangle, int row, int col){
    if(row == triangle.size()-1){
        return triangle[row][col];
    }

    // Move to ith column
    int down = helper(triangle, row+1, col) + triangle[row][col];

    // Move to (i+1)th column
    int downPlusOne = helper(triangle, row+1, col+1) + triangle[row][col];
    return min(down, downPlusOne);
}

int minimumTotal(vector<vector<int>>& triangle) {
    int row = 0;
    int col = 0;
    return helper(triangle, row, col);
}

int main(){
    vector<vector<int>> triangle {{2},
                                  {3,4},
                                  {6,5,7},
                                  {4,1,8,3}};
    cout << minimumTotal(triangle);
    return 0;
}