#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int numRollsToTargetHelper(int dices, int faces, int target, vector<vector<int>> &dp){
    // Base conditions
    if(target < 0) return 0;
    if(dices == 0 && target != 0) return 0;
    if(dices !=0 && target == 0) return 0;
    if(dices == 0 && target == 0) return 1;

    // Return dp answer
    if(dp[dices][target] != -1) return dp[dices][target];

    // According to the question add long long so that 
    // the answer can evaluate itself
    long long ans = 0;
    for(int i=1; i<=faces; i++){
        // Take the remainder as mentioned in case 3 with 10^9 + 7
        ans = (ans + numRollsToTargetHelper(dices-1, faces, target-i, dp)) % MOD;
    }
    return dp[dices][target] = ans;
}

int numRollsToTarget(int dices, int faces, int target) {
    vector<vector<int>> dp(dices+1, vector<int>(target+1, -1));
    int ans = numRollsToTargetHelper(dices, faces, target, dp) ;
    return ans;
}

int main(){
    int dices = 30;
    int faces = 30;
    int target = 500;
    cout << numRollsToTarget(dices,faces,target);
    return 0;
}