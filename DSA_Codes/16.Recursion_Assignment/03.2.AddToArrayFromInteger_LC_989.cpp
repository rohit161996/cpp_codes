#include<bits/stdc++.h>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
    int index = num.size() - 1;
    int carry = 0;

    while (index >= 0 || k > 0) {
        int sum = carry;

        // Add the current digit of num if index is valid
        if (index >= 0) {
            sum += num[index];
        }

        // Add the current digit of k
        sum += k % 10;

        // Calculate the digit to store and the carry
        int digit = sum % 10;
        carry = sum / 10;

        // Store the digit in the correct position
        if (index >= 0) {
            num[index] = digit;
        } else {
            num.insert(num.begin(), digit);
        }

        // Move to the next digit of k and decrement the index
        k /= 10;
        if (index >= 0) {
            index--;
        }
    }

    // If there is a carry left, insert it at the beginning
    if (carry) {
        num.insert(num.begin(), carry);
    }

    return num;
}

int main(){
    vector<int> num = {9,9,9,9};
    int k = 1;
    addToArrayForm(num, k);
    for(auto it:num){
        cout << it << " "; 
    }
    return 0;
}