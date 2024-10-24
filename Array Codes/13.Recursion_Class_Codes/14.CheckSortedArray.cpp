#include<bits/stdc++.h>
using namespace std;

bool checkSorted(int arr[], int size, int index){
    // Base case
    if(index == size-1){
        return true;
    }
    bool recursionAns = false;
    bool currAns = false;
    // Solve 1 case
    if(arr[index] <= arr[index+1]){
        currAns = true;
    }

    // Solving by recursion
    recursionAns = checkSorted(arr, size, index+1);

    return (currAns && recursionAns);
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int index  = 0;

    cout << checkSorted(arr, size, index);
    return 0;
}
