#include<bits/stdc++.h>
using namespace std;

void printEven(int arr[], int size, int index){
    // Base case if index equals size return 
    if(index == size){
        return;
    }

    // Solving one case
    if(!(arr[index]&1)){
        cout << arr[index] << " ";
    }

    // Solving rest of the cases 
    printEven(arr, size, index+1);
}

void printEven2(int arr[], int size, int index, vector<int>& ans){
    // Base case if index equals size return 
    if(index == size){
        return;
    }

    // Solving one case
    if(!(arr[index]&1)){
        ans.push_back(arr[index]);
    }

    // Solving rest of the cases 
    printEven2(arr, size, index+1, ans);
}

int main(){
    int size = 7;
    int index = 0;
    int arr[] = {87, 10, 23, 30, 45, 51, 60};
    printEven(arr, size, index);
    cout << endl;

    vector<int> ans;
    printEven2(arr, size, index, ans);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}