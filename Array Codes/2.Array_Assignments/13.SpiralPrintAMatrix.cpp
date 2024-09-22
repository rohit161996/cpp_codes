#include<bits/stdc++.h>
using namespace std;

vector<int> spiral_print(vector<vector <int>> arr){
    vector<int> ans;
    int mrow = arr.size();
    int ncol = arr[0].size();
    int total_cnt = mrow * ncol;

    int startingRow = 0;
    int endingRow = mrow-1;

    int startingColumn = 0;
    int endingColumn = ncol -1;

    int count = 0;
    while(count < total_cnt){
        //Starting row
        for(int i=startingColumn; i<=endingColumn && count < total_cnt; i++){
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;

        // Ending Column
        for(int i=startingRow; i<=endingRow && count < total_cnt; i++){
            ans.push_back(arr[i][endingColumn]);
            count++;
        }
        endingColumn--;

        // Ending Row
        for(int i=endingColumn; i>=startingColumn && count < total_cnt; i--){
            ans.push_back(arr[endingRow][i]);
            count++;
        }
        endingRow--;

        // Starting Column
        for(int i=endingRow; i>=startingRow && count < total_cnt; i--){
            ans.push_back(arr[i][startingColumn]);
            count++;
        }
        startingColumn++;
    }

    return ans;
}


int main(){

    vector<vector <int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> ans;

    ans = spiral_print(arr);
    
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}