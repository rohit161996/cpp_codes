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

void reverse(char arr[], int size){

    int length = getLength(arr, size);

    int start = 0;
    int end = length-1;

    while(start <= end){
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    char arr[100] = "rohit";
    
    cout << " The original string is "<< arr << endl;
    reverse(arr, 100);

    cout << " The reverse string is "<< arr << endl;

    return 0;
}