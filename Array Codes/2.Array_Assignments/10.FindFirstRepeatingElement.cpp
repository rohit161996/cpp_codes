#include <bits/stdc++.h>
using namespace std;

int find_first_repeating_element(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> map;
    for(int i=0; i<n; i++){
        map[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(map[arr[i]] > 1){
            return i+1;
        }
    }
    return -1;
}

int main(){
    
    vector<int> arr = {1,2,3,4,4,5,6,7,7};

    int ans = find_first_repeating_element(arr);
    cout << ans;

    return 0;
}