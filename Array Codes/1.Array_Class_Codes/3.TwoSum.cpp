#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(int arr[], int size, int target){
    
    pair<int, int> ans = make_pair(-1,-1);
    // Take an element
    for(int i=0; i<size; i++){

        // Add it with the other elements of the array.
        // compare it with target if it is equal return
        // both the elements
        for(int j=i+1; j<size; j++){

            if(arr[i]+arr[j]==target){
                ans.first = arr[i];
                ans.second = arr[j];
                return ans;
            }

        }
    }
    // There is no pair equal to target
    return ans;
}

int main(){
    int arr[] = {10, 5, 20, 15, 30};
    int size = 5;
    int target = 35;

    pair<int,int> ans = twoSum(arr, size, target);
    cout << "The pair is "<< ans.first <<" and "<< ans.second;
    return 0;
}