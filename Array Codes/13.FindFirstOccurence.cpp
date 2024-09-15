#include<bits/stdc++.h>
using namespace std;

void find_first_occurence(int arr[], int size, int &ansIndex, int target){
    int start = 0;
    int end = size-1;
    int mid = start + ((end-start)/2);

    while(start <= end){
        if(arr[mid] == target){
            // Answer is found store and move on to the left
            ansIndex = mid+1;

            // Move to the left
            end = mid -1;
        }
        else if(arr[mid] < target){
            // Move to the right
            start = mid + 1;
        }
        else{
            // Move to the left
            end = mid - 1;
        }
        mid = start + ((end - start)/2);
    }
}

int main(){
    int ansIndex = -1;
    int arr[] = {20,20,20,20,20,30,40,50,60,60,60,70};
    int size = 12;
    find_first_occurence(arr, 12, ansIndex, 60);

    cout << "First Occurence is at "<< ansIndex;
    return 0;
}