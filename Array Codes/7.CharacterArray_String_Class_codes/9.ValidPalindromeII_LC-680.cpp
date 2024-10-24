#include<bits/stdc++.h>
using namespace std;

// Description :- We can remove atmost 1 character to make the string palindrome
// I/P -> "aba", "absa" "abcdabbcadcba" etc.
// O/P -> True since we can remove c and the string will be palindrome

bool checkPalindrome(string str, int s, int e){
    while(s <= e){
        // Check if the characters are same 
        // Shrink the two pointers
        if(str[s] == str[e]){
            s++;
            e--;
        }
        // Return false if not equal
        else{
            return false;
        }
    }
    // Return true if the string passed is palindrome
    return true;
}

bool validPalindrome(string s) {
    int start = 0;
    int end = s.size()-1;
    while(start <= end){
        // If the value is same from starting and ending 
        // Shrink the two pointer window
        if(s[start] ==  s[end]){
            start++;
            end--;
        }
        // If the value of the characters are not same
        else{
            // There are two possibilities shrink the pointer from end
            bool answerOne = checkPalindrome(s, start, end-1);
            
            // or shrink the pointer from the start
            bool answerTwo = checkPalindrome(s, start+1, end);

            // If any of the possibility is palindrome return true or return false
            bool finalAnswer = answerOne || answerTwo;
            return finalAnswer;
        }
    }
    return true;
}

int main(){
    string check = "abcdabbcadcba";
    validPalindrome(check) ? cout << "String is a palindrome" << endl: cout << "String is not a palindrome" << endl;
    return 0;
}