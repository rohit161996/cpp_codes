#include<bits/stdc++.h>
using namespace std;

void mergeProcedure(vector<int> arr, int n1, vector<int> brr, int n2, vector<int> &ans){
    int i=0;
    int j=0;

    // Merge two sorted array by comparing the corresponding elements
    while(i < n1 && j < n2){
        if(arr[i] < brr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(brr[j]);
            j++;
        }
    }

    // If elements in the first array are still left
    while(i < n1){
        ans.push_back(arr[i]);
        i++;
    }

    // If elements in the second array are still left
    while(j < n2){
        ans.push_back(brr[j]);
        j++;
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i,j,k;
    // Points to the last real element of the first array
    i = m-1;
    // Points to the last real element of the second array
    j = n-1;
    //Points to the last index of the first array
    k = m+n-1;

    // run till one of the array is exhausted 
    // starting from the back
    while(i >= 0 && j >= 0){
        // if the second array has larger element
        // store it from the end
        if(nums1[i] < nums2[j]){
            nums1[k--] = nums2[j--];
        }
        // if the first array has larger element
        // store it from the end
        else{
            nums1[k--] = nums1[i--];
        }
    }

    // If second array is exhausted
    while(i >= 0)
        nums1[k--] = nums1[i--];
    
    // If first array is exhausted
    while(j >= 0)
        nums1[k--] = nums2[j--];        
}

int main(){
    vector<int> nums1 = {10, 20, 30, 40, 50, 60, 0 ,0 ,0, 0};
    int n1 = 6;
    
    vector<int> nums2 = {11, 21, 31, 41};
    int n2 = 4;
    merge(nums1, n1, nums2, n2);

    for(auto it : nums1){
        cout << it << " ";
    }
    return 0;
}