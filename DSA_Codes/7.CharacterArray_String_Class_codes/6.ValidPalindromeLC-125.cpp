#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    string ans = "";
    int len = s.size();

    // Remove the spaces from the string and non alphanumeric 
    // characters from the string
    for(int i=0; i<len; i++){
        if(s[i] != ' '){
            // Check if the character lies between A to Z
            // If yes convert in a to z and Insert in the answer
            char currCharacter = s[i];
            if( currCharacter >= 'A' && currCharacter <= 'Z' ){
                currCharacter += 32;
                ans.push_back(currCharacter);
            }
            else if( currCharacter >= 'a' && currCharacter <= 'z' ){
                ans.push_back(currCharacter);
            }
            else if( currCharacter >= '0' && currCharacter <= '9' ){
                ans.push_back(currCharacter);
            }
        }
    }

    // check the converted string is a palindrome or not
    int start = 0;
    int end = ans.length()-1;
    while(start <= end){
        if(ans[start] != ans[end]){
            // Not a palindrome
            return false;
        }
        start++;
        end--;
    }
    // Palindrome 
    return true;
}

int main(){
    string check = "abbaca";
    isPalindrome(check) ? cout << "Palindrome" << endl : cout << "Not a Palindrome" << endl ;
    return 0;
}