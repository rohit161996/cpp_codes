#include<bits/stdc++.h>
using namespace std;

// I/P -> "daabcbaabcbc"
// O/P -> "dab"

// Using majorly stl functions
string removeAllSubstring(string s, string part){  // Pattern can exist for atmost n/k times
    while(s.find(part) != string::npos){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    string ans = removeAllSubstring(s, part);
    cout << "The final string remaining is " << ans << endl;
    return 0;
}