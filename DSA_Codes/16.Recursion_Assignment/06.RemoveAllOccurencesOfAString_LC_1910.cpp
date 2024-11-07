#include<bits/stdc++.h>
using namespace std;

// Time complexity is O(n^2) = O(nm * n/m)
void removeOccurence(string &s, string &part){
    // Find the location of the substring in the main string
    int position = s.find(part);

    // Check if the part is present in the main string 
    if(position != string::npos){
        // Solving 1 Case
        string left = s.substr(0, position);
        string right = s.substr(position+part.size(), s.size());
        s = left + right;

        // Solving rest of the cases by recursion
        removeOccurence(s, part);
    }
    else{
        // Base case when the part is not found in the main string
        return;
    }
}

string removeOccurrences(string &s, string &part) {
    removeOccurence(s,part);
    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string p = "abc";
    removeOccurrences(s, p);
    cout << s;
    return 0;
}