#include <bits/stdc++.h>
using namespace std;

// Note Pass the dp array by reference otherwise
// the dp array will create the memory exceeded error
int solve(int n, vector<int> &dp){
    // Base case
    // If number becomes 0 problem is solved
    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    // set the number of perfect squares required
    // as the number itself
    int no_of_num_req = n;

    // run loop till the square is less than the number
    for(int i=1; i*i <= n; i++){
        int temp = i*i;

        // Update the number in recursion
        no_of_num_req = min(no_of_num_req, 1 + solve(n-temp, dp));
    }
    dp[n] = no_of_num_req;
    return dp[n];
}

int numSquares(int n) {
    vector<int> dp(n+1, -1);
    int ans = solve(n, dp);
    return ans;
}

int main(){
    int n = 40;
    cout << numSquares(40);
    return 0;
}