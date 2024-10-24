#include<bits/stdc++.h>
using namespace std;

int binary_search_iterative(int arr[], int index, int size, int target){
    int start = index;
    int end = size;
    int mid = start + ((end-start)/2);
    while (start <= end)
    {
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + ((end-start)/2);
    }
    return -1;
}

int binary_search(int arr[], int size, int start, int end, int target){
    // Base case returning condition
    if(start > end){
        return -1;
    }

    int mid = start + ((end-start)/2);
    // Base case if mid is equal to target
    if(arr[mid] == target){
        return mid;
    }
    // Move to the left
    else if(arr[mid] > target){
        return binary_search(arr, size, start, mid-1, target);
    }
    // Move to the right
    else{
        return binary_search(arr, size, mid+1, end, target);
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = 8;
    int target = 70;
    int index = 0;

    cout << binary_search(arr, size, 0, 7, target) << endl;
    // cout << binary_search_iterative(arr, index, size, target) << endl;

    return 0;
}