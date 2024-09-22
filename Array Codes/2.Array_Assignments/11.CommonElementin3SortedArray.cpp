#include <bits/stdc++.h>
using namespace std;

#define M 6
#define N 5
#define O 8

vector<int> common_element(int A[], int B[], int C[], 
                           int M1,  int N1,  int O1){
    // Initialize the answer
    vector<int> ans;

    // Initialize the counters
    int i,j,k;
    i=j=k=0;

    while(i < M1 && j < N1 && k < O1){
        // If the elements are equal push it to answer
        // increment the pointers
        if(A[i] == B[j] && B[j] == C[k]){
            ans.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        // Move the first array's pointer forward if element is
        // less than the second array's element.
        else if(A[i] < B[j]){
            i++;
        }
        // Move the second array's pointer forward if element is
        // less than the third array's element.
        else if(B[j] < C[k]){
            j++;
        }
        // Increase the third pointer.
        else{
            k++;
        }
    }
    return ans;
}

int main(){
    int ARR[M] = {1,5,10,20,40,80};
    int BRR[N] = {6,7,20,80,100};
    int CRR[O] = {3,4,15,20,30,70,80,100};

    vector<int> ans;
    ans = common_element(ARR, BRR, CRR, M, N, O);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}