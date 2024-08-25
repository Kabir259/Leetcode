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

        vector<vector<int>> dp(c+2, vector<int>(c+2,0));

        // for(int i = 0; i<dp.size(); i++){
        //     for(int j = 0; j<dp[0].size(); j++){
        //         if(j>i) dp[i][j]=0;
        //     }
        // }

        for(int i = c; i>=1; i--){
            for(int j = i; j<=c; j++){
                if (i > j) continue; // maintain the original recursive funcns for loop's implicit relation
                int mini = 1e9;

                for(int k = i; k<=j; k++){ // k's parameters are the SAME as recursive function for loop of k's bounds
                    int cost = dp[i][k-1] + dp[k+1][j] + cuts[j+1]-cuts[i-1];
                    mini = min(mini, cost);
                }
                dp[i][j]=mini;
            }
        }

        return dp[1][c];
    }

};