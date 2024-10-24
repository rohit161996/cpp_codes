#include<bits/stdc++.h>
using namespace std;

// Printing the odd numbers as identified.
void printOdds(int arr[], int size, int index){
    // Base case if index equals size return 
    if(index == size){
        return;
    }

    // Solving one case
    if(arr[index]&1){
        cout << arr[index] << " ";
    }

    // Solving rest of the cases 
    printOdds(arr, size, index+1);
}

// Storing the odd numbers in answer vectors.
void printOdds2(int arr[], int size, int index, vector<int>& ans){
    // Base case if index equals size return 
    if(index == size){
        return;
    }

    // Solving one case
    if(arr[index]&1){
        ans.push_back(arr[index]);
    }

    // Solving rest of the cases 
    printOdds2(arr, size, index+1, ans);
}

int main(){
    int size = 7;
    int index = 0;
    int arr[] = {87, 10, 23, 30, 45, 51, 60};
    printOdds(arr, size, index);
    cout << endl;

    vector<int> ans;
    printOdds2(arr, size, index, ans);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}