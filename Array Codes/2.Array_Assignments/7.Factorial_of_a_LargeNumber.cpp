#include<bits/stdc++.h>
using namespace std;

vector<int> fact_large(int N){

    vector<int> ans = {1};
    int carry = 0;
    int digit = 0;
    for(int i=2; i<=N; i++){
        for(int j=0; j<ans.size(); j++){
            int x = (ans[j] * i) + carry;
            digit = x % 10;
            carry = x/10;
            ans[j] = digit;
        }
        // If carry is very large then store it digit wise
        while(carry){
            int digit = carry % 10;
            ans.push_back(digit);
            carry = carry/10;
        }
        carry = 0;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    int N = 5;
    vector<int> ans;
    ans = fact_large(N);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
    }
    
    cout << endl;

    return 0;
}