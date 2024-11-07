#include<bits/stdc++.h>
using namespace std;

int getLength(char arr[], int size){
    int length = 0;
    int index = 0;
    int n = size;
    while(index < n){
        if(arr[index] == '\0'){
            break;
        }
        else{
            length++;
        }
        index++;
    }
    return length;
}

bool checkPalindrome(char arr[], int size){
    int length = getLength(arr, size);

    int start = 0;
    int end = length-1;

    while(start <= end){
        if(arr[start] == arr[end]){
            // Move start towards end
            // and end towards start
            start++;
            end--;
        }
        else{
            // If not equal return false
            return false;
        }
    }
    // If we reach here means string is a plaindrome
    return true;
}

int main(){
    char arr[100] = "nitin";
    
    cout << " The original string is "<< arr << endl;
    checkPalindrome(arr, 100) ? cout << " The string is paindrome " << endl : cout << " The string is not a paindrome " << endl ;
    return 0;
}