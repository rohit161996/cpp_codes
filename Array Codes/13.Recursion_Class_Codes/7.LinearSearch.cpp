#include<bits/stdc++.h>
 using namespace std;

/*
 * Linear Search in an Array
 *
 * @parameter 1 : Array
 * @parameter 2 : Target
 * 
 * @return : index of the target
 */

bool linear_search(int arr[], int size, int target, int index){
    // Base case if element not found
    if(index >= size){
        cout << "Not Found Index :" << index << endl;
        cout << "Not Found Target :" << target << endl;
        return -1;
    }

    // Base case if element is found
    if(arr[index] == target){
        cout << "Found Index :" << index << endl;
        cout << "Found Target :" << target << endl;
        return true;
    }

    // Recursion will solve rest of the problem
    bool ans = linear_search(arr, size, target, index+1);
    return ans;
}

 int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size  = 6;
    int target = 100;
    int index = 0;
    cout << linear_search(arr, size, target, index);
    return 0;
 }