#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int traverse = 0;
    int sort_pointer = 0;
    
    // traverse through the array
    while(traverse < nums.size()){
        // traverse points to the same as sort_pointer 
        // increment traverse
        if(nums[traverse] == nums[sort_pointer]){
            traverse++;
        }
        // if traverse does not point to the same value as sort_pointer
        else{
            // get the value at sort_pointer for sorting
            sort_pointer++;
            nums[sort_pointer] = nums[traverse];
            
            // move the traverse forward
            traverse++;
        }
    }
    return sort_pointer+1;
}

int main(){
    vector<int> nums = {0,0,1,1,2,3,3,4,4,5,5,6};

    int ans = removeDuplicates(nums);
    cout << ans;

    return 0;
}