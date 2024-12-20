#include<bits/stdc++.h>
using namespace std;

int maxArray(int arr[], int size, int& ans, int index){
    // Base case or stopping condition
    if(index == size){
        // Entire array is traversed
        return ans;
    }

    // Solving one case or Processing
    if(ans < arr[index]){
        ans = arr[index];
    }

    // Handing over the other cases to Recursion
    return maxArray(arr, size, ans, index+1);
}


int main(){
    int size = 6;
    int ans = INT_MIN;
    int index = 0;
    int arr[] = {80, 10, 20, 30, 40, 50, 60};

    cout << maxArray(arr, size, ans, index);
    return 0;
}
