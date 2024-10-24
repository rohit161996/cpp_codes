#include<bits/stdc++.h>
using namespace std;

// Remove all the adjacent duplicates from the string
// I/P -> "abbaca"
// O/P -> "ca"

// abbaca -> aaca -> ca
// So the answer is ca
string removeDuplicates(string s) {
    // Initialize answer string as empty string
    string ans = "";
    int length = s.size();

    for(int i=0; i<length; i++){
        char currCharacter = s[i];
        // If answer is empty insert the current character in the answer vector
        if(ans.empty()){
            ans.push_back(currCharacter);
        }
        // If the current element is same as the element stores in the answer 
        // vector previously pop that character from the answer vector
        else if(currCharacter == ans.back()){
            ans.pop_back();
        }
        // If the current element is not same as the element stores in the answer 
        // vector previously insert the character to the answer vector
        else if(currCharacter != ans.back()){
            ans.push_back(currCharacter);
        }
    }
    return ans;
}

int main(){
    string check = "abbaca";
    string ans = removeDuplicates(check);
    cout << ans;
    return 0;
}