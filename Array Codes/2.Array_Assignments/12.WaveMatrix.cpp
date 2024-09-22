#include<bits/stdc++.h>
using namespace std;

vector<int> wave_print(vector<vector <int>> nums){
    // Calculate nrows and ncols
    int mrows = nums.size();
    int ncols = nums[0].size();

    // Initialize answer
    vector<int> ans;

    int even_odd = 0;
    for(int i=0; i<ncols; i++){
        // If the column is even 
        if(even_odd % 2 == 0){
            // print it from top to down.
            for(int j=0; j<mrows; j++){
                ans.push_back(nums[j][i]);
            }
        }
        // If the column is odd
        else{
        // print it from bottom to top.
            for(int j=mrows-1; j>=0; j--){
                ans.push_back(nums[j][i]);
            }
        }
        even_odd++;
    }
    return ans;
}


int main(){
    vector<vector <int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}, {7,8,9}};
    vector<int> ans;

    ans = wave_print(arr);
    
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}