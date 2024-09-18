#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int ansIndex = 0;
    int start  = 0;
    int end = arr.size()-1;
    int mid = start + ( (end-start)/2);

    while(start <= end){
        // On line A or increasing order
        if(arr[mid] < arr[mid+1]){
            start = mid+1;
        }
        // On line B or decreasing order or peak
        // Store and compute used 
        else{
            ansIndex = mid;
            end = mid-1;
        }
        mid = start + ( (end-start)/2);
    }
    return ansIndex;
}

int main(){
    vector<int> arr = {0,10,5,2};
    
    int peak_value = peakIndexInMountainArray(arr);
    cout << peak_value;

    return 0;
}