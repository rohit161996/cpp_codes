#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& coins, int amount){
    // If amount reaches 0 return no coin required
    if(amount == 0){
        return 0;
    }

    // Initialize minimum coins required as a large number
    int minCoinsAns = INT_MAX;

    // traverse the array and check of the coin can contribute to the amount
    for(int i=0; i<coins.size(); i++){
        // Take the coin
        int coin = coins[i];

        // Check if the coin value is less than amount 
        if(coin <= amount){
            // Call recursive function 
            int recursionAns = helper(coins, amount-coin);

            // If recursion gives reasonable answer
            if(recursionAns != INT_MAX){
                // add coin to the answer
                int coinsUsed = 1 + recursionAns;

                // update the global answer between minimum coins and current answer
                minCoinsAns = min(coinsUsed, minCoinsAns);
            }
        }
    }
    return minCoinsAns;
}

int coinChange(vector<int>& coins, int amount) {
    int ans = helper(coins, amount);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 8;
    int ans = coinChange(coins, amount);
    cout << ans;
    return 0;
}