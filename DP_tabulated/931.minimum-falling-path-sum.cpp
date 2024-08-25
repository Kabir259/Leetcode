/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n));

        for(int i = m-1; i>=0;i--){
            for(int j = 0; j<n; j++){
                if(i==m-1){
                    dp[i][j]=matrix[i][j];
                }
            }
        }

        for(int i = m-2; i>=0;i--){
            for(int j = 0; j<n; j++){
                int a  = i+1<m?dp[i+1][j]:1e9;
                int b = (i+1<m)&&(j-1>=0)?dp[i+1][j-1]:1e9;
                int c = (i+1<m)&&(j+1<n)?dp[i+1][j+1]:1e9;
                dp[i][j]=matrix[i][j]+min(a,min(b,c));
            }
        }

        int ans = 1e9;
        for(int j=0;j<n;j++){
            int temp = dp[0][j];
            ans = min(ans,temp);
        }
        return ans;

    }
};
// @lc code=end

