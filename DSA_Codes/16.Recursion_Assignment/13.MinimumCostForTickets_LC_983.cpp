#include <bits/stdc++.h>
using namespace std;

int mincostTicketsHelper(vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
    if(index >= days.size()){
        return 0;
    }

    // Return stored result
    if(dp[index] != -1) return dp[index];

    // One Day Pass is taken
    int cost1 = costs[0] + mincostTicketsHelper(days, costs, index+1, dp);

    // Seven Days Pass is Taken
    int passEndsAt = days[index] + 7 - 1;
    int j = index;
    while(j < days.size() && days[j] <= passEndsAt){
        j++;
    }
    int cost7 = costs[1] + mincostTicketsHelper(days, costs, j, dp);

    // Thirty Days Pass is Taken
    passEndsAt = days[index] + 30 - 1;
    j = index;
    while(j < days.size() && days[j] <= passEndsAt){
        j++;
    }
    int cost30 = costs[2] + mincostTicketsHelper(days, costs, j, dp);

    dp[index] = min(cost1, min(cost7, cost30));
    return dp[index];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.size()+1, -1);
    int ans = mincostTicketsHelper(days, costs, 0, dp);
    return ans;
}

int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout << mincostTickets(days, costs);
    return 0;
}