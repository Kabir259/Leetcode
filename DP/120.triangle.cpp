/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the bottom row of dp with the values from the triangle
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }
        
        // Bottom-up approach to calculate the minimum path sum
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
            // the reason why j isnt computed backwards despite having 
            // j+1 in the transition equation is because check out the initialisation
            // for dp i,j we have already computed j and j+1 in the i+1th row
            // only i needs to go backwards
        }
        
        return dp[0][0];
    }
};




// class Solution {
// public:

//     int f(int i, int j, int grid[200][200],
//         int dp[200][200], int iFinal, int jFinal){
//         if(i<0 || j<0){
//         return 0;
//         }
//         if(i==0 && j==0){
//         return grid[i][j];
//         }
//         if(dp[i][j]!=-1){
//         return dp[i][j];
//         }
//         int down = f(i-1, j, grid, dp, iFinal, jFinal);
//         int downLeft = f(i-1, j-1, grid, dp, iFinal, jFinal);
//         int left = f(i, j-1, grid, dp, iFinal, jFinal);
//         dp[i][j] = grid[i][j] + min(down, min(downLeft, left));
//         return dp[i][j];
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int bottom = triangle[triangle.size()-1].size();
        
//         int grid[bottom][bottom];
//         int dp[bottom][bottom];
//         memset(dp, 0, sizeof(dp));

//         for(int i=0;i<triangle.size();i++){
//             for(int j = 0; j<triangle[i].size(); j++){
//                 grid[i][j]=triangle[i][j];
//                 dp[i][j]=-1;
//             }
//         }

//         // now you have the grid and dp array initialised;
//         int ans = 1e9;
//         for(int i=0;i<bottom;i++){
//             int ans1 = f(0,0,grid,dp,bottom-1,i);
//             ans = min(ans,ans1);
//         }
//         return ans;

//     }
// };
