#include<bits/stdc++.h>
using namespace std;
bool ans_is_present_k_1_times(string ans, int k_1, char check){
    char ch = check;
    int it = ans.size()-1;
    for(int z=0; z<k_1; z++){
        if(ans[it] != ch)
            return false;
        it--;
    }
    return true;
}

//Brute Force
string removeDuplicates_brute(string s, int k) {
    string ans;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(ans.size() < k-1){
            ans.push_back(s[i]);
        }
        else{
            if(ans_is_present_k_1_times(ans, k-1, s[i])){
                for(int j=0; j<k-1; j++)
                    ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
    }
    return ans;
}

// Extra Space is used in terms of an array
string removeDuplicates2(string s, int k){
    int n = s.size();
    int i,j;
    i = j = 0;
    // i points to the location where we want to insert the value after removing duplicates
    // j always moves forward 
    vector<int> count(n);
    while(j < n){
        // Place the value of jth char in ith value
        s[i] = s[j];

        // Initialize the count of the ith character as 1
        count[i] = 1;

        // If the value of the ith character is same as i-1th character
        // Increment the value of that index in count array
        if(i>0 && (s[i] == s[i-1])){
            count[i] += count[i-1];
        }

        // If the value is equal to k move i backwards
        if(count[i] == k){
            i -= k;
        }
        i++; j++;
    }
    return s.substr(0,i);
}

int main(){
    string check = "deeedbbcccbdaa";
    int k = 3;
    string ans = removeDuplicates2(check, k);
    cout << "The string after removing duplicates is : "<< ans << endl; 
    return 0;
}