#include<bits/stdc++.h>
using namespace std;

bool helper(vector<vector<char>>& board, string word, int row, int col, int index){
    // if index length matches the word length return true
    if(index == word.length()){
        return true;
    }
    
    // Base case
    if(row<0 || row>=board.size() || 
        col<0 || col>=board[0].size() || 
        board[row][col] != word[index]){
        return false;
    }

    // If we have reached here it means row and col are with boundaries
    // and board[row][col] == word[index]
    char curr = word[index];
    board[row][col] = '$';
    bool ans = helper(board, word, row-1, col, index+1) || // up
                helper(board, word, row+1, col, index+1) || // down
                helper(board, word, row, col-1, index+1) || // left
                helper(board, word, row, col+1, index+1);   // right
    board[row][col] = curr;
    return ans;
}

bool exist(vector<vector<char>>& board, string word) {
    // Start from all letters one by one
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            // Pass board, word, row, col, number of letters added
            if(helper(board, word, i, j, 0)){
                return true;                    
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board  {{'A','B','C','E'},
                                 {'S','F','C','S'},
                                 {'A','D','E','E'}};
    string word = "ABCCEE";
    cout << exist(board, word);
    return 0;
}