#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int end, int mid){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int *leftarr = new int[leftLength];
    int *rightarr = new int[rightLength];

    // 1. Copy the elements into left array
    int index = start;
    for(int i=0; i<leftLength; i++){
        leftarr[i] = arr[index++];
    }

    // 2. Copy the elements into the right array
    index = mid+1;
    for(int i=0; i<rightLength; i++){
        rightarr[i] = arr[index++];
    }

    // Merge Left and right array
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    // 3.1 Merging two arrays
    while(leftIndex < leftLength && rightIndex < rightLength){
        // Compare left and right array's elements ans store lesser in main array
        if(leftarr[leftIndex] < rightarr[rightIndex]){
            arr[mainArrayIndex++] = leftarr[leftIndex++];
        }
        else{
            arr[mainArrayIndex++] = rightarr[rightIndex++];
        }
    }

    // 3.2 If right array is exhausted
    while(leftIndex < leftLength){
        arr[mainArrayIndex++] = leftarr[leftIndex++];
    }

    // 3.3 If left array is exhausted
    while(rightIndex < rightLength){
        arr[mainArrayIndex++] = rightarr[rightIndex++];
    }

    // 4. Delete heap memory
    delete[] leftarr;
    delete[] rightarr;
}

void mergeSort(int arr[], int start, int end){
    // Base Case
    if(start >= end){
        return;
    }

    int mid = start + ((end-start)/2);

    // Sort left part of the array
    mergeSort(arr, start, mid);

    // Sort right part of the array
    mergeSort(arr, mid+1, end);

    // Merge sorted array
    merge(arr, start, end, mid);
}

int main(){
    int arr[] = {35, 5, 65, 21, 57, 12, 36, 2, 4, 15, 87};
    for(int i=0; i<11; i++){
        cout << arr[i] << " ";
    }cout << endl;
    mergeSort(arr, 0, 10);

    for(int i=0; i<11; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
