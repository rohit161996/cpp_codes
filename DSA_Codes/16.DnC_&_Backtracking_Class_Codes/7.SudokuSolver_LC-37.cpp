#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, char digit, vector<vector<char>>& board){
    int n = board.size();
    // Check for the row
    for(int i=0; i<n; i++){
        // Element exists in row
        if(board[row][i] == digit){
            return false;
        }
    }

    // Check for the column
    for(int j=0; j<n; j++){
        // Element exist in the column
        if(board[j][col] == digit){
            return false;
        }
    }

    // Check for the box
    // Formula to check the box row -> [(3*(row/3))+(k/3)]
    // Formula to check the box column -> [(3*(col/3))+(k%3)]
    for(int k=0; k<n; k++){
        if(board[(3*(row/3))+(k/3)][(3*(col/3))+(k%3)] == digit){
            return false;
        }
    }
    return true;
}

bool helper(vector<vector<char>>& board){
    // Solve 1 case 
    // find the empty cell
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            // Check for empty cell
            if(board[i][j] == '.'){
                // Try to fit digit 1 to 9 on the cell
                for(char digit='1'; digit<='9'; digit++){
                    // Check if it is safe to place the digit on the board
                    if(isSafe(i, j, digit, board) == true){
                        // Place the digit if it is safe
                        board[i][j] = digit;
                        // Solving by recursion
                        bool solved = helper(board);
                        // If the entire board is solved
                        if(solved == true){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                    }
                }
                // No digit fits from 1 to 9
                // Backtracking
                return false;
            }
        }
    }
    // Sudoku is solved completely
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board);
}

int main(){
    vector<vector<char>> board   {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};

    // vector<vector<char>> board   {{'.','.','.','.','.','.','.','.','.'},
    //                               {'.','.','.','.','.','.','.','.','.'},
    //                               {'.','.','.','.','.','.','.','.','.'},
    //                               {'.','.','.','.','.','.','.','.','.'},
    //                               {'.','.','.','.','.','.','.','.','.'},
    //                               {'.','.','.','.','.','.','.','.','.'},
    //                               {'.','.','.','.','.','.','.','.','.'},
    //                               {'.','.','.','.','.','.','.','.','.'},
    //                               {'.','.','.','.','.','.','.','.','.'}};    
    solveSudoku(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
