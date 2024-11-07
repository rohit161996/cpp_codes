/*
 * Rat in a Maze Problem
 * There is a maze in form of a 2D Array
 * Rat can access some cells and  
 * cannot access some other cells.
 *
 * Time Complexity = (n^n)
 */

#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> mat, vector<vector<bool>> &visited, int n,
            vector<string> &ans, int srcx, int srcy, int destx, int desty, string output){
    if(destx == srcx && desty == srcy){
        ans.push_back(output);
        return;
    }
    
    // Go Up (i-1, j)
    if(srcx-1 >= 0 && visited[srcx-1][srcy] == 0 && mat[srcx-1][srcy] != 0){
        visited[srcx-1][srcy] = 1;
        helper(mat, visited, n, ans, srcx-1, srcy, destx, desty, output+"U");
        // Backtracking
        visited[srcx-1][srcy] = 0;
    }
    
    // Go Left (i, j-1)
    if(srcy-1 >= 0 && visited[srcx][srcy-1] == 0 && mat[srcx][srcy-1] != 0){
        visited[srcx][srcy-1] = 1;
        helper(mat, visited, n, ans, srcx, srcy-1, destx, desty, output+"L");
        // Backtracking
        visited[srcx][srcy-1] = 0;
    }
    
    // Go Down (i+1, j)
    if(srcx+1 < n && visited[srcx+1][srcy] == 0 && mat[srcx+1][srcy] != 0){
        visited[srcx+1][srcy] = 1;
        helper(mat, visited, n, ans, srcx+1, srcy, destx, desty, output+"D");
        // Backtracking
        visited[srcx+1][srcy] = 0;
    }
    
    // Go Right (i, j+1)
    if(srcy+1 < n && visited[srcx][srcy+1] == 0 && mat[srcx][srcy+1] != 0){
        visited[srcx][srcy+1] = 1;
        helper(mat, visited, n, ans, srcx, srcy+1, destx, desty, output+"R");
        // Backtracking
        visited[srcx][srcy+1] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &mat) {
    // Size of the row of the maze
    int n = mat.size();

    // Answer vector having the paths
    vector<string> ans;
    
    // Visited 2D array 
    vector<vector<bool>> visited(n, vector<bool>(n,0));
    visited[0][0]= 1;
    int srcx = 0;
    int srcy = 0;
    int destx = n-1;
    int desty = n-1;
    string output = "";
    
    // Important condition
    if(mat[0][0] == 0){
        return ans;
    }
    
    helper(mat, visited, n, ans, srcx, srcy, destx, desty, output);
    
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1}, 
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    // cout << mat.size() << endl;
    // cout << mat[0].size() << endl;
    vector<string> ans = findPath(mat);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}

