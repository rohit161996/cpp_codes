#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();

    // Calculate sum of total numbers
    int sum = (n * (n+1))/2;

    // Subtract the numbers from the total sum to get the answer
    for(int i=0; i<n; i++){
        sum = sum - nums[i];
    }

    // Return the answer
    return sum;
}

int missingNumber_xor_num(vector<int>& nums) {
    int n = nums.size();
    int xor_num = 0;

    // Calculate sum of total numbers
    for(int i=1; i<=n; i++){
        xor_num = xor_num ^ i;
    }

    // Subtract the numbers from the total sum to get the answer
    for(int i=0; i<n; i++){
        xor_num = xor_num ^ nums[i];
    }

    // Return the answer
    return xor_num;
}

int main(){

    vector<int> arr = {3, 0, 1};

    int ans = missingNumber_xor_num(arr);
    cout << ans << " ";

    return 0;
}
