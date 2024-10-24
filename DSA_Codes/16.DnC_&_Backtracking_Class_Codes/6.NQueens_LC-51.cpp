#include<bits/stdc++.h>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> lowerDiagonalCheck;
unordered_map<int,bool> upperDiagonalCheck;

bool isSafe(int row, int col, vector<vector<char>> board){
    // Brute approach -> traverse board O(n^2)
    // Optimal time -> O(n)
    // row check
    if(rowCheck[row] == true){
        // Not safe
        return false;
    }
    
    // upper diagonal check
    if(lowerDiagonalCheck[row+col] == true){
        // Not safe
        return false;
    }

    // lower diagonal check
    if(upperDiagonalCheck[row-col] == true){
        // Not safe
        return false;
    }
    // safe
    return true;
}

void storeSolution(vector<vector<string>> &ans, vector<vector<char>> &board, int n){
        vector<string> tempAns;
        for(int i=0; i<n; i++){
            string output = "";
            for(int j=0; j<n; j++){
                output.push_back(board[i][j]);
            }
            // Store string in the temporary answer
            tempAns.push_back(output);
        }
        // Store vector of string in the answer
        ans.push_back(tempAns);
}

void solve(int n, vector<vector<char>> &board, vector<vector<string>> &ans, int col){
    // Base case if we have placed queen in all rows
    if(col >= n){
        // all queens are placed 
        // store board arrangements in ans
        storeSolution(ans, board, n);
        return;
    }

    // Solve 1 case by recursion and rest will be handled by recursion
    // We have column index, decide here in which row we are placing the queen
    for(int row=0; row<n; row++){
        // Place the queen after checking that we can keep the queen there
        if(isSafe(row, col, board)){
            board[row][col] = 'Q';
            rowCheck[row] = true;
            lowerDiagonalCheck[row+col] = true;
            upperDiagonalCheck[row-col] = true;

            // Rest leave it to recursion
            solve(n, board, ans, col+1);
            
            // Backtracking
            board[row][col] = '.';
            rowCheck[row] = false;
            lowerDiagonalCheck[row+col] = false;
            upperDiagonalCheck[row-col] = false;
        }
    }

}

vector<vector<string>> solveNQueens(int n) {
    // Answer having vector of strings
    vector<vector<string>> ans;

    // Board
    vector<vector<char>> board(n, vector<char>(n, '.'));

    // Starting from column = 0
    int col = 0;
    solve(n, board, ans, col);
    return ans;
}

int main(){
    int queens = 4;
    vector<vector<string>> ans;
    ans = solveNQueens(queens);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}