#include <bits/stdc++.h>
using namespace std;

/*
 * What is Recursion?
 * When a function calls itself directly or
 * indirectly it is called recursion.
 * 
 * 
 * What is Recursion?
 * When a big problem can be solved by a
 * small problem it is called recursion.
 * 
 * Solve 1 case rest recursion will take care.
 * 
 */

int factorial(int n){
    // Base case since 1! = 1 or 0! = 1 
    if(n == 1 || n == 0){
        return 1;
    }

    // Recursion will do rest of the work
    int recursionAns = factorial(n-1);

    /* If code is written here it will execute first 
     * hence it is called HEAD RECURSION.
     */
    int fact = n * recursionAns;
    /* If the code is written here it will execute after 
     * hence it is called TAIL RECURSION.
     */

    // Return Answer
    return fact;
}

int main(){
    int n = 5;
    cout << factorial(n);
    return 0;
}