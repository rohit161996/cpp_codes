#include<bits/stdc++.h>
using namespace std;

int power(int n){
    // Base case 2^0 = 1
    if(n==0){
        return 1;
    }

    // Recursion will solve the rest of the case
    int recursionAns = power(n-1);
    int power = 2 * recursionAns;

    // Return answer
    return power;
}

int main(){
    int n = 5;
    cout << "2 raise to the power n gives : "<< power(n);
    return 0;
}