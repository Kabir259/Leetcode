#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[102][102];

    int f(int i, int j, vector<int>& cuts){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;

        for(int k=i;k<=j;k++){
            // dp[i][j] = f(i,k-1,cuts) + f(k+1,j,cuts) + cuts[j+1]-cuts[i-1];
            /*NEVER DO THIS. WHILE CALCULATING MINI< USE A COST TO UPDATE MINI NOT DP[i][j]*/
            int cost;
            cost = f(i,k-1,cuts) + f(k+1,j,cuts) + cuts[j+1]-cuts[i-1];
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;

    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        memset(dp,-1,sizeof(dp));

        return f(1,c,cuts);

    }

};