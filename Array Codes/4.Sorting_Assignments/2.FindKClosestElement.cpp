#include <bits/stdc++.h>
using namespace std;

vector<int> findKClosestElement_twoPointers(vector<int> nums, int k, int x){
    int n = nums.size();
    int low = 0;
    int high = n-1;

    // We need the window size of k
    while(high-low >= k){
        // If the low difference is greater
        if(x-nums[low] > nums[high]-x){
            // Move the low value
            low++;
        }
        // If the high difference is greater
        else{
            // Move the high value
            high--;
        }
    }

    // Initialize the answer vector and store the values from low to high
    vector<int> ans;
    for(int i=low; i<=high; i++){
        ans.push_back(nums[i]);
    }

    // Time complexity of this will be O(n-k) since we made n-k comparisions.
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 5;
    int x = 7;

    vector<int> ans = findKClosestElement_twoPointers(nums, k, x);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " " ;
    }
    cout << endl;

    return 0;
}