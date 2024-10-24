#include<bits/stdc++.h>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperDiagonalCheck;
unordered_map<int, bool> lowerDiagonalCheck;

bool isSafe(int row, int col, vector<vector<char>> &board){
    // check row
    if(rowCheck[row] == true){
        return false;
    }

    // check upper diagonal
    if(upperDiagonalCheck[row-col] == true){
        return false;
    }

    // check lower diagonal
    if(lowerDiagonalCheck[row+col] == true){
        return false;
    }
    return true;
}

void helper(int n, vector<vector<char>> &board, int &ans_count, int col){
    if(col >= n){
        ans_count++;
        return;
    }

    // Solve 1 case and rest with recursion and backtracking
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board)){
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperDiagonalCheck[row-col] = true;
            lowerDiagonalCheck[row+col] = true;

            helper(n, board, ans_count, col+1);

            board[row][col] = '.';
            rowCheck[row] = false;
            upperDiagonalCheck[row-col] = false;
            lowerDiagonalCheck[row+col] = false;
        }
    }
}

int totalNQueens(int n) {
    // Number of Solutions possible
    int ans_count = 0;

    // create a board to solve the problem
    vector<vector<char>> board(n, vector<char>(n, '.'));

    // solve column wise
    int col = 0;
    helper(n, board, ans_count, col);

    return ans_count;
}

int main(){
    cout << totalNQueens(4);
    return 0;
}