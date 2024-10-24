#include <bits/stdc++.h>
using namespace std;

int findPairs_twoPointers(vector<int>& nums, int k) {
    // Sort the array
    sort(nums.begin(), nums.end());

    // Calculate the size
    int n = nums.size();

    // Take two pointers
    int i=0; int j = 1;

    // Take answer set to avoid duplicates
    set<pair<int,int>> ans;
    // Expand the two pointers till the array size
    while(j < n){
        int diff = nums[j]-nums[i];
        if(diff == k){
            // Insert the answer in the set
            ans.insert({nums[i], nums[j]});
            i++; j++;
        }
        else if(diff < k){
            // Expand the space
            j++;
        }
        else{
            // Shrink the space
            i++;
        }
        if(i==j){
            // i and j should not be equal
            j++;
        }
    }
    return ans.size();
}

bool binarySearch(vector<int>& nums, int target, int start, int end){
    bool ans = 0;
    int s = start;
    int e = end;
    int m = s+((e-s)/2);
    while(s <= e){
        if(nums[m] == target){
            ans = 1;
            break;
        }
        else if(nums[m] < target){
            s = m + 1;
        }
        else{
            e = m - 1;
        }
        m = s + ((e-s)/2);
    }

    return ans;
}

int findPairs_binarysearch(vector<int>& nums, int k) {
    // sort the array
    sort(nums.begin(), nums.end());

    // Initialize the answer set
    set<pair<int,int>> ans;

    // take an element one by one 
    int n = nums.size();
    for(int i=0; i<n; i++){

        // Find element in the remaining array
        if(binarySearch(nums, nums[i]+k, i+1, n-1)){
        
            // If found store the pair in the set
            ans.insert({nums[i], k-nums[i]});
        }
    }

    return ans.size();
}

int main(){

    vector<int> nums = {1,2,3,4,5,6};
    int target = 1;

    int ans = findPairs_twoPointers(nums, target);
    cout << "The number of unique pairs are " << ans << endl;

    int ans_bs = findPairs_binarysearch(nums, target);
    cout << "The number of unique pairs are " << ans_bs << endl;

    return 0;
}