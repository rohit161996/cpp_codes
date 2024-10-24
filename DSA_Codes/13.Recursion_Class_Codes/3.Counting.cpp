#include<bits/stdc++.h>
using namespace std;

void countFrom1toN(int n){
    // Base Case Print(1)
    if(n == 1){
        cout << "1 ";
        return ;
    }

    // Recursion call
    countFrom1toN(n-1);

    // Tail Recursion Print forwards 
    // the function call
    cout << n << " ";

    return ;
}

void countFromNto1(int n){
    // Base Case Print(1)
    if(n == 1){
        cout << "1 ";
        return ;
    }

    // Head Recursion Print backward 
    // the function call
    cout << n << " ";
    
    // Recursion call
    countFromNto1(n-1);
    return ;
}

int main(){
    int N = 10;    
    // Print count from 1 to N
    countFrom1toN(N);

    cout << endl;

    // Print count from N to 1
    countFromNto1(N);
    return 0;
}
