#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoSum_brute(int arr[], int size, int target){
    
    pair<int, int> ans = make_pair(-1,-1);
    // Take an element
    for(int i=0; i<size; i++){

        // Add it with the other elements of the array.
        // compare it with target if it is equal return
        // both the elements
        for(int j=i+1; j<size; j++){

            if(arr[i]+arr[j]==target){
                ans.first = arr[i];
                ans.second = arr[j];
                return ans;
            }

        }
    }
    // There is no pair equal to target
    return ans;
}

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> map;
    vector<int> ans;

    // Store the index along with the difference in the map
    for(int i=0; i<nums.size(); i++){
        // If the element's pair is not found in the map
        // Store it in the map
        if(map.find(target-nums[i]) == map.end()){
            map[nums[i]] = i;
        }
        // If for element pair is found store in the answer
        else{
            ans.push_back(i);
            ans.push_back(map[target-nums[i]]);
        }
    }
    return ans;
}

int main(){
    int arr[] = {10, 5, 20, 15, 30};
    int size = 5;
    int target = 35;

    pair<int,int> ans = twoSum_brute(arr, size, target);
    cout << "The pair is "<< ans.first <<" and "<< ans.second << endl;

    vector<int> nums = {2,5,7,9,11};
    target = 9;

    vector<int> ans_op = twoSum(nums, target);
    for(int i=0; i<2; i++){
        cout << ans_op[i] << " ";
    }
    cout  << endl;

    return 0;
}

