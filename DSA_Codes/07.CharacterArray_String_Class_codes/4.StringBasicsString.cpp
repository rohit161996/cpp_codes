#include<bits/stdc++.h>
using namespace std;

int main(){
    string name;

    // By default the delimeter is '\n' '\t' ' '
    // cin >> name;

    // Enter is the only delimeter in getline function
    // for string getline is used and for char array cin.getline is used
    getline(cin, name, '\n');

    // cout << name;
    auto it = name.begin();
    while(it != name.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;

    string main = "Hello ji kaise ho saare";
    string find_main = "kaise";

    cout << main.find(find_main) << endl;

    return 0;
}