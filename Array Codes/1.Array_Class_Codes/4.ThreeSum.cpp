#include <bits/stdc++.h>
using namespace std;

void checkthreeSum(int arr[], int n, int target) 
{
    // Take and element
    for(int i=0; i<n; i++){
        // Take others other than previous
        // add and compare with the target
        // if all three are there return them.
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k] == target){
                    cout << arr[i] << "," << arr[j] << "," << arr[k] << endl;
                }
            }
        }
    }
}

int main(){
    int arr[] = {10, 5, 20, 15, 30};
    int size = 5;
    int target = 35;

    checkthreeSum(arr, size, target);

    return 0;
}