#include<bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2) {
    string ans = "";
    int n = num1.size()-1;
    int m = num2.size()-1;
    int carry = 0;
    int sum = 0;
    // Add till both strings counter are there
    while(n >=0 && m >= 0){
        // Add both the numbers from the string 
        // Subtract '0' from the character to convert to the number 
        sum = (num1[n]-'0') + (num2[m]-'0') + carry;
        
        // Take the units place
        int digit = sum%10;

        // Take the carry
        carry = sum/10;

        // Store into the answer 
        // Add + '0' to convert the integer to character
        ans += digit + '0';

        // Decrement the counter
        n--; m--;
    }

    // Add till first string is not processed
    while(n >= 0){
        // Calculate the sum from the first string
        sum = (num1[n]-'0') + carry;

        // get the unit digit
        int digit = sum%10;

        // calculate the carry
        carry = sum/10;

        // add the digit to the answer
        ans += digit + '0';
        n--;
    }

    // Add till second string is not processed
    while(m >= 0){
        // Calculate the sum from the second string
        sum = (num2[m]-'0') + carry;

        // Calculate the unit's digit
        int digit = sum%10;

        // Calculate the carry
        carry = sum/10;

        // add the digit to the answer
        ans += digit + '0';
        m--;
    }
    // Add the carry to the answer if carry is not 0
    if(carry) ans += carry + '0';

    // Reverse the ans string
    // Since we are calculating from behind
    reverse(ans.begin(), ans.end());

    // Return the answer
    return ans;
}

string addStrings_compact(string num1, string num2){
    int n = num1.size()-1;
    int m = num2.size()-1;
    int carry = 0;
    string ans = "";
    while(n>=0 || m>=0 || carry>0){
        int sum = carry;
        if(n>=0){
            sum += num1[n] - '0';
            n--;
        }

        if(m>=0){
            sum += num2[m] - '0';
            m--;
        }

        int digit = sum%10;
        carry = sum/10;
        ans += digit+'0';
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void addRE(string num1, int p1, string num2, int p2, string &ans, int &carry){
    // Base case
    if(p1<0 && p2<0){
        if(carry){
            ans += carry+'0';
        }
        return;
    }

    // Solving 1 case
    int n1 = p1>=0 ? num1[p1] - '0' : 0;
    int n2 = p2>=0 ? num2[p2] - '0' : 0;
    int sum = n1 + n2 + carry;
    int digit = sum%10;
    carry = sum/10;
    ans += digit+'0';

    // Solving other cases by recursion
    addRE(num1, p1-1, num2, p2-1, ans, carry);
}

string addStringsRe(string num1, string num2){
    string ans = "";
    int carry = 0;
    int n = num1.size()-1;
    int m = num2.size()-1;
    addRE(num1, n, num2, m, ans, carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s1 = "11";
    string s2 = "123";
    string ans = addStringsRe(s1, s2);
    cout << ans;
    return 0;
}

