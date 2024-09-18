#include <bits/stdc++.h>
using namespace std;

int getQuotient(int divident, int divisor){
    int start = -1 * divident;
    int end = divident;
    int mid = start + ((end-start)/2);

    int ans = INT_MIN;
    while(start <= end){
        int val = mid * divisor;
        if(val == divident){
            ans = mid;
            break;
        }
        else if(val < divident){
            // Store
            ans = mid;

            // Move to the right
            start = mid + 1;
        }
        else{
            // Move to the left
            end = mid - 1;
        }
        mid = start + ((end-start)/2);
    }
    return ans;
}

int main(){

    int divd = -17;
    int divs = -4;

    // Aim is to find the quotient
    int ans = getQuotient(abs(divd), abs(divs));

    if((divd < 0) && (divs > 0)){
        ans = ans * -1;
    }
    if((divd > 0) && (divs < 0)){
        ans = ans * -1;
    }
    cout << "The quotient is "<< ans;


    return 0;
}
