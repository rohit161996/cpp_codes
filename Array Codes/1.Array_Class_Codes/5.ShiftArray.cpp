#include <bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int size, int rotateN){
    int n = rotateN % size;
    int temp[1000];

    /* No shift required */
    if(n==0){
        return;
    }

    /* Store the last final shift elements into the temp array */
    int index = 0;
    for(int i=size-n; i<size; i++){
        temp[index] = arr[i];
        index++;
    }

    /* Shift the rest of the elements */
    for(int i=size-1; i>=0; i--){
        arr[i] = arr[i-n];
    }

    /* Now move the temp array elements to the array */
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;

    rotateArray(arr, size, 8);
    
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}