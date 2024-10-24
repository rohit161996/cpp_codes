#include<bits/stdc++.h>
using namespace std;

void printDigits(int x){
    // Base condition that if the number is less than equal to 0.
    if(x <= 0){
        return;
    }

    // Get digit from the number 
    int digit = x % 10;

    // Make recursive calls
    printDigits(x/10);

    // Print the digit from beginning
    cout << digit << endl;
}

int main(){
    int n = 389;
    printDigits(n);
    return 0;
}