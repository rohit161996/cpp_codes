#include <bits/stdc++.h>
using namespace std;

void printpermutation(string str, int index){
    // Base case
    if(index >= str.length()){
        cout << str << endl;
        return;
    }

    // Solving 1 case
    // on the ith box try to place every character
    for(int j = index; j < str.length(); j++){
        // Placing the character in the ith box
        swap(str[index], str[j]);

        // Recursion solving the rest of the cases
        printpermutation(str, index+1);
    }
}

int main(){
    string str = "abc";
    int index = 0;
    printpermutation(str, index);
    return 0;
}