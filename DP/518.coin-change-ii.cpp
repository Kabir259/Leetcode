/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1));

        for(int i =0;i<=n; i++){
            for(int j = 0; j<=amount;j++){
                if(i==0){
                    dp[i][j]=0;// if i have no array then no combo will fill my knapsack
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j]; // unbounded knapsack
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        int ans = dp[n][amount];
        // if(ans==1e9){
        //     return -1;
        // }
        return ans;
    }
};
// @lc code=end

