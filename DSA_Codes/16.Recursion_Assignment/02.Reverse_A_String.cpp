#include<bits/stdc++.h>
using namespace std;

void reverse(string &s, int start, int end){
    // Base case
    // start exceeds end
    if(start >= end){
        return;
    }

    // Solve 1 case
    swap(s[start], s[end]);

    // Solve rest of the cases by recursion 
    reverse(s, start+1, end-1);
}

int main(){
    // Check for edge cases e.g. single letter etc.
    string s = "rohit";

    // pass index as well i.e. start and end
    int start = 0;
    int end = s.size();

    // print string before reversing
    cout << s << endl;
    
    // reverse the string
    reverse(s, start, end-1);

    // print string after reversing
    cout << s << endl;
    return 0;
}
