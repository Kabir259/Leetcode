/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// int f(int i, int j, 
// vector<vector<int>>& grid, vector<vector<int>>& dp){
//     int m = grid.size();
//     int n = grid[0].size();
//     if(i==m-1 && j==n-1){
//         return grid[i][j];
//     }
//     if(i>=m || j>=n){ // grid me yehi out of bound case hota hai
//         return 1e9;// agar tu grid ke hi bahar chala gya to 
//         //path sum chaye infintiy hojaye but tu kabhi pohoch
//         // nai payega final point ke pass
//     }
//     if(dp[i][j]!=1e9){return dp[i][j];}
//     int right = f(i,j+1,grid,dp)+grid[i][j];
//     int down = f(i+1,j,grid,dp)+grid[i][j];
//     return dp[i][j]= min(right,down);
// }

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,1e9));
//         return f(0,0,grid,dp);
//     }
// };



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i =m-1; i>=0;i--){
            for(int j = n-1; j>=0; j--){
                if(i==m-1 && j==n-1){
                    dp[m-1][n-1]=grid[m-1][n-1];
                    continue;
                }
                int right = (j+1<n)?dp[i][j+1]+grid[i][j]:1e9;
                int down = (i+1<m)?dp[i+1][j]+grid[i][j]:1e9;
                dp[i][j]=min(right,down);
            }
        }
        return dp[0][0];
    }
};



// @lc code=end

