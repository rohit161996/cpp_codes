#include <bits/stdc++.h>
using namespace std;

int findSingleElement(int arr[], int size)
{
    int ans = 0;

    // To find the single repeating element 
    // we need to XOR all the elements
    for(int i=0; i<size; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){
    int arr[] = {2,5,2,1,5,4,3,1,3};
    int size = 9;

    int ans;
    ans = findSingleElement(arr, size);
    cout << "The single element is " << ans << endl;
    return 0;
}