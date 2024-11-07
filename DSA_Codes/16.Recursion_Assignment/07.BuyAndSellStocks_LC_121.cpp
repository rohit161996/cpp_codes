#include <bits/stdc++.h>
using namespace std;
void findMaxProfit(vector<int>& prices, int &minPrice, int &maxPro, int index){
    if(index == prices.size()){
        return;
    }

    // Solving 1 case
    if(prices[index] < minPrice){
        minPrice = prices[index];
    }
    if(maxPro < prices[index]-minPrice){
        maxPro = prices[index]-minPrice;
    }

    // Solving other cases by recursion
    findMaxProfit(prices, minPrice, maxPro, index+1);
}

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxPro = INT_MIN;
    findMaxProfit(prices, minPrice, maxPro, 0);
    return maxPro;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}