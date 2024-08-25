/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1));

        for(int i =0;i<=n; i++){
            for(int j = 0; j<=amount;j++){
                if(i==0){
                    dp[i][j]=1e9;// if i have no array then how many coins will it take to fill the knapsack?
                }
                if(j==0){
                    dp[i][j]=0;
                }
            }
        }
        dp[0][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]); // unbounded knapsack
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        int ans = dp[n][amount];
        if(ans==1e9){
            return -1;
        }
        return ans;

    }
};
// @lc code=end

