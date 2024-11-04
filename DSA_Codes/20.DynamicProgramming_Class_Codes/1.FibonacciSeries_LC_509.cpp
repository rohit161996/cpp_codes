#include <bits/stdc++.h>
using namespace std;

int iterativeFib(int n){
    int n1 = 0;
    int n2 = 1;
    // First number
    if(n == 0){
        return 0;
    }
    // Second number
    if(n == 1){
        return 1;
    }
    int temp = 0;
    // finding the nth number
    for(int i=2; i<=n;i++){
        // Storing the first in temp
        temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    }
    return temp;
}

int recursiveFib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    int ans = recursiveFib(n-1) + recursiveFib(n-2);
    return ans;
}

// top-down approach
// 1D DP Array since only one parameter is changing
int dpFibTDN(vector<int> &dp, int n){
    // Return first number 
    // Base case
    if(n == 0){
        return 0;
    }

    // Return second number 
    // Base case
    if(n == 1){
        return 1;
    }

    // 3. After base case check if answer is stored, return if stored
    if(dp[n] != -1){
        return dp[n];
    }

    // 2. Store the answer in dp array and return it
    dp[n] = dpFibTDN(dp, n-1) + dpFibTDN(dp, n-2);
    return dp[n];
}

// bottom-up approach
int dpFibBUP(int n){
    // Step 1: Create dp array
    vector<int> dp(n+1, -1);

    // Step 2: Analyze base case and update dp array
    dp[0] = 0;
    if(n == 0) return dp[0];

    dp[1] = 1;
    if(n == 1) return dp[1];

    // Step 3. Check parameter and reverse it and run a loop
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fib(int n) {
    // return iterativeFib(n);
    // return recursiveFib(n);

    // Step 1. Create a dp array and pass in the function
    // vector<int> dp(n+1, -1);
    // return dpFibTDN(dp, n);

    return dpFibBUP(n);
}

int main(){
    cout << fib(10);
    return 0;
}