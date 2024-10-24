#include<bits/stdc++.h>
using namespace std;

int getSum(int n){
    // Base case
    if(n == 1){
        return 1;
    }
    
    // Recursion answer
    int recursionAns = getSum(n-1);

    // return answer
    return (n + recursionAns);
}

int main(){
    int n = 10;

    int ans = getSum(n);
    cout << "The answer is " << ans;
    return 0;
}