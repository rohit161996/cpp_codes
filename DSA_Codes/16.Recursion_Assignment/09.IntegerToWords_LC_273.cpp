#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> words = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"},
                                    {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
                                    {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"},
                                    {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"},
                                    {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
                                    {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
                                    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"},
                                    {2, "Two"}, {1, "One"}};

string numberToWords(int num) {
    // E.G. num = 12,234
    if(num == 0){
        return "Zero";
    }
    string ans = "";
    for(auto it : words){
        // 12,234(num) >= 1000(it)
        if(num >= it.first){
            // big_money = 12
            string big_sum = "";
            if(num >= 100){
                big_sum = numberToWords(num / it.first) + " ";
            }

            // value from the map i.e thousand, hundred etc.
            string word_val = it.second;

            // change from the money i.e. 234
            string change = "";
            if(num % it.first != 0){
                change = " " + numberToWords(num % it.first);
            }
            return big_sum + word_val + change;
        }
    }
    return ans;
}

int main(){
    int num = 122345;
    cout << numberToWords(num);
    return 0;
}