#include <bits/stdc++.h>
using namespace std;

bool validAnagram(string s, string p){
    // Calculate the length of the strings
    int s_length = s.size();
    int p_length = p.size();

    // If the length is not equal return false
    if(s_length != p_length) return false;

    unordered_map<char,int> map;
    for(int i=0; i<s_length; i++){
        // Increment the character count of s
        // Decrement the character count of p
        map[s[i]]++;
        map[p[i]]--;
    }
    
    // Check that count of all the characters are 0
    // If they are not 0 return false.
    for(auto it : map){
        if(it.second){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "car";
    string p = "arc";
    cout << validAnagram(s, p);
    return 0;
}