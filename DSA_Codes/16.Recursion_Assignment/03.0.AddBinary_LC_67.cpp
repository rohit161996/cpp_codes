#include <bits/stdc++.h>
using namespace std;

// Same question as add two strings
// Division and mnodulo is replaced by 2 instead of 10
string addBinary(string a, string b) {
    string ans = "";
    int n = a.size()-1;
    int m = b.size()-1;
    int carry = 0;
    while(m>=0 || n >=0 || carry>0){
        int sum = carry;
        if(n>=0){
            sum += a[n] - '0';
            n--;
        }
        if(m>=0){
            sum += b[m] - '0';
            m--;
        }
        // Get the remainder and divide by 2 instead of 10
        int digit = sum % 2;
        carry = sum/2;
        ans += digit+'0';
    }
    // Reverse the answer to get the final answer
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string a = "1101";
    string b = "111";
    cout << addBinary(a, b);
    return 0;
}