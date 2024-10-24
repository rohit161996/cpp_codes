#include<bits/stdc++.h>
using namespace std;

void printArrayFromStartToEnd(int arr[], int size){
    // Base Case of Recursion
    if(size == 0){
        cout << arr[0] << " ";
        return;
    }

    // Other cases
    printArrayFromStartToEnd(arr, size-1);
    cout << arr[size] << " ";
    return;
}

void printArrayFromEndToStart(int arr[], int size){
    // Base Case of Recursion
    if(size == 0){
        cout << arr[0] << " ";
        return;
    }

    // Other cases
    cout << arr[size] << " ";
    printArrayFromEndToStart(arr, size-1);
    return;
}

void printArray1toN(int arr[], int size, int index){
    // Base Case of Recursion
    if(size == index){
        // Return if the index reaches the end
        return;
    }

    // One case handling
    cout << arr[index] << " ";

    // Rest is handled by recursion
    printArray1toN(arr, size, index+1);
    return;
}

void printArrayNto1(int arr[], int size, int index){
    // Base Case of Recursion
    if(index == -1){
        // Return if the index reaches the end
        return;
    }

    // One case handling
    cout << arr[index] << " ";

    // Rest is handled by recursion
    printArrayNto1(arr, size, index-1);
    return;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    int index = 0;

    // Print from start to end using tail recursion
    printArrayFromStartToEnd(arr, size-1);
    cout << endl;

    // Print from end to start using head recursion
    printArrayFromEndToStart(arr, size-1);
    cout << endl;

    // Print from start to end using index tracking
    printArray1toN(arr, size, index);
    cout << endl;

    // Print from end to start using index tracking
    printArrayNto1(arr, size, size-1);
    cout << endl;
    return 0;
}

