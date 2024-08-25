/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int range=0;
        for(int i =0; i<n; i++){
            range+=nums[i];
        }
        if(range%2!=0){
            return false;
        }
        else{
            vector<vector<bool>> dp(n+1,vector<bool>((range/2)+1));
            for(int i =0;i<=n;i++){
                for(int j=0;j<=range/2;j++){
                    if(i==0){
                        dp[i][j]=false;
                    }
                    if(j==0){
                        dp[i][j]=true;
                    }
                }
            }
            dp[0][0]=true;

            for(int i =1; i<=n;i++){
                for(int j=0;j<=range/2;j++){
                    if(nums[i-1]<=j){
                        dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }

            return dp[n][range/2];
        }
    }
};
// @lc code=end

