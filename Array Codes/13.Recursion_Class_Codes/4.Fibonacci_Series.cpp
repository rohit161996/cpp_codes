#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n == 1){
        // cout << "0 ";
        return 0;
    }
    if(n == 2){
        // cout << "1 ";
        return 1;
    }
    
    // Recursion solves rest of the cases
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){
    int n = 10;
    fib(n);
    return 0;
}