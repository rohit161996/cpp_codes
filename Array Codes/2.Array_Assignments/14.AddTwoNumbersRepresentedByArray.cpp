#include<bits/stdc++.h>
using namespace std;

string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
    // Calculate the size of the arrays
    int m = arr1.size();
    int n = arr2.size();

    // Initalize carry and digit and answer
    int carry = 0;
    int digit = 0;    
    string ans;

    // Initialize the counter to both arrays
    int i, j;
    i = m-1;
    j = n-1;

    // Take elements from both the array
    // Add them with carry
    // take the unit digit and add the number to answer
    while(i>=0 && j>=0){
        int x = arr1[i] + arr2[j] + carry;
        // cout << x << " " << endl;
        digit = x % 10;
        carry = x / 10;
        ans.push_back(digit + '0');
        i--;j--;
    }

    // Take element from the first array
    // Add it with carry
    // take the unit digit and add the number to answer
    while(i>=0){
        int x = arr1[i] + 0 + carry;
        // cout << x << " " << endl;
        digit = x % 10;
        carry = x/10;
        ans.push_back(digit + '0');
        i--;
    }

    // Take element from the second array
    // Add it with carry
    // take the unit digit and add the number to answer
    while(j>=0){
        int x = 0 + arr2[j] + carry;
        // cout << x << " " << endl;
        digit = x % 10;
        carry = x/10;
        ans.push_back(digit + '0');
        j--;
    }

    while(carry){
        int digit = carry % 10;
        ans.push_back(carry + '0');
        carry = carry / 10;
    }

    while(ans[ans.size()-1] == '0'){
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr1 = {9, 5, 4, 9};
    vector<int> arr2 =    {8, 1, 4};

    // Answer is 10363
    string ans = calc_Sum(arr1,arr2);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
    }

    return 0;
}