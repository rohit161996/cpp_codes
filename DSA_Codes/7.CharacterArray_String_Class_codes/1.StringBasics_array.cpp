#include<bits/stdc++.h>
using namespace std;

// original char -> '@'
// new char -> ' '
void replaceCharacter(char originalChar, char newChar, char arr[], int size){
    for(int i=0; i<size; i++){
        if(arr[i] == originalChar){
            arr[i] = newChar;
        }
    }
}

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

int main(){
    char name[100] = "My@Name@Is@Rohit@Ramchandani";
    // @aim : checking the ascii values of the letters
    // cout << name[0] << " " << (int)name[0] << endl;
    // cout << name[1] << " " << (int)name[1] << endl;
    // cout << name[2] << " " << (int)name[2] << endl;
    // cout << name[3] << " " << (int)name[3] << endl;
    // cout << name[4] << " " << (int)name[4] << endl;
    // cout << name[5] << " " << (int)name[5] << endl;
    // cout << name[6] << " " << (int)name[6] << endl;

    
    // cout << "Enter your name: " << endl;
    // cin >> name;

    // @argument1 : base address
    // @argument2 : the size of max data which will be stored
    // cin.getline(name, 100);


    cout << "Original String : " << name << endl;
    replaceCharacter('@', ' ', name, 28);
    cout << "Replaced String : " << name << endl;
    cout << getLength(name, 100);
    return 0;
}