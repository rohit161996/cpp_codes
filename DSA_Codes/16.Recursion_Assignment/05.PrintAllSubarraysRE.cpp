#include<bits/stdc++.h>
using namespace std;

void printSubarrays_util(vector<int> num, int start, int end){
    // Base case
    if(start > end){
        return;
    }

    // Solve rest of the cases by recursion
    printSubarrays_util(num, start, end-1);

    // Solve 1 case
    for(int i=start; i<=end; i++){
        cout << num[i] << " ";
    }
    cout << endl;
}

void printSubarrays(vector<int> num){
    for(int i=0; i<num.size(); i++){
        printSubarrays_util(num, i, num.size()-1);
        cout << endl;
    }
}

int main(){
    vector<int> num = {10, 20, 30, 40, 50};
    int start = 0;
    int end = num.size()-1;
    printSubarrays(num);
    return 0;
}



