#include <bits/stdc++.h>
using namespace std;

int find_char_iterative(string &s, char x){
    int index = -1;
    for(int i=0; i<s.size(); i++){
        if(s[i] == x){
            index = i;
        }
    }
    return index;
}

// Find the last occuring element from front
int find_char_recursive(string &s, char x, int index, int &ans){
    // Base case
    if(s[index] == x){
        ans = index;
        // Do not return since we need to check further for the last element
    }

    // If index reaches out of the array return ans
    if(index == s.size()){
        return ans;
    }
    
    // Solve the rest of the cases by recursion
    find_char_recursive(s, x, index+1, ans);
}

// Find the last occuring element from the end
int last_occuring_recursive(string &s, char x, int index, int &ans){
    // Base case that element is found
    if(s[index] == x){
        ans = index;
        return ans;
    }

    // Termination condition
    if(index < 0){
        return ans;
    }

    last_occuring_recursive(s, x, index-1, ans);
}

int main(){
    string s = "abcddedg";
    char x = 'd';
    int ans = -1;
    cout << "The element is found at "<< find_char_iterative(s,x) << endl;
    cout << "The element is found at "<< find_char_recursive(s,x,0,ans) << endl;
    cout << "The element is found at "<< find_char_recursive(s,x,s.size()-1,ans);
    return 0;
}