#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int start, int mid, int end){
    int count = 0;
    int leftlength = mid-start+1;
    int rightlength = end-mid;
    
    // This part can be replaced by using vector instead of manual memory management
    int *leftarr = new int[leftlength];
    int *rightarr = new int[rightlength];
    
    // Copy the contents of the left and right array to the corresponding array
    int index = start;
    for(int i=0; i<leftlength; i++)
        leftarr[i] = arr[index++];
    
    index = mid+1;
    for(int i=0; i<rightlength; i++)
        rightarr[i] = arr[index++];
        
    // Merge the two arrays
    int left = 0;
    int right = 0;
    int storage_counter = start;
    while(left < leftlength && right < rightlength){
        if(leftarr[left] <= rightarr[right]){
            arr[storage_counter++] = leftarr[left++];
        }
        else{// Required case where count should be increased
            arr[storage_counter++] = rightarr[right++];
            // This is the only line which is changed in the function of merge sort
            count += leftlength - left;
        }
    }

    while(left < leftlength){
        arr[storage_counter++] = leftarr[left++];
    }

    while(right < rightlength){
        arr[storage_counter++] = rightarr[right++];
    }
    
    delete[] leftarr;
    delete[] rightarr;
    
    return count;
}

int mergeSort(vector<int> &arr, int start, int end){
    int count = 0;
    
    if(start >= end){
        return 0;
    }
    
    int mid = start + (end-start)/2;
    
    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid+1, end);
    count += merge(arr, start, mid, end);
    
    return count;
}

// Function to count inversions in the array.
int inversionCount(vector<int> &arr) {
    int count = mergeSort(arr, 0, arr.size()-1);
    return count;
}

int main(){
    vector<int> arr = {24, 18, 38, 43, 14, 40, 1, 54};
    cout << inversionCount(arr);
    return 0;
}