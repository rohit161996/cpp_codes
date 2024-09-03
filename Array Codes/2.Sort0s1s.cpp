#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void sort_0s_1s_counting(int arr[], int size){
    int zero = 0;
    int one = 0;
    for(int i=0; i<size; i++){
        if(arr[i]==0){
            zero++;
        }
        else if(arr[i]==1){
            one++;
        }
    }
    int i=0;
    for(; zero!=0; i++){
        arr[i] = 0;
        zero--;
    }

    for(; one!=0; i++){
        arr[i] = 1;
        one--;
    }
}

void sort_0s_1s_fillmethod(int arr[], int size){
    int zero = 0;
    int one = 0;
    for(int i=0; i<size; i++){
        if(arr[i]==0){
            zero++;
        }
        else if(arr[i]==1){
            one++;
        }
    }
    fill(arr, arr+zero, 0);
    fill(arr+zero, arr+size, 1);
}

void sort_function(int arr[], int size)
{
    sort(arr,arr+size);
}

void sort_0s_1s_twopointer(int arr[], int size){
    int zero = 0;
    int one = 0;
    while(one == size-1){
        if(one == 1){
            one++;
        }
        if(one == 0){
            arr[++zero] = 0;
            arr[one++] = 1;
        }
    }
}

int main(){
    int arr[] = {0,1,1,0,0,1,1,1};
    int size = 8;

    sort_0s_1s_twopointer(arr, size);
    
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}