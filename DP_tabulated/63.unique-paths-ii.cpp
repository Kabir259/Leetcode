#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
//         if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
//             return 0;
//         }
//         int m=obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,0));
//         for(int i = m-1; i>=0; i--){
//             for(int j = n-1; j>=0; j--){
//                 if(i==m-1 && j==n-1 && !obstacleGrid[m-1][n-1]){
//                     dp[m-1][n-1]=1;
//                 }
//                 else if(i==m-1 && j==n-1 && obstacleGrid[m-1][n-1]){
//                     break;
//                 }
//                 else if(i==m-1 && j!=n-1 && !obstacleGrid[m-1][j+1]){
//                     dp[m-1][j]=dp[m-1][j+1];
//                 }
//                 else if(i==m-1 && j!=n-1 && obstacleGrid[m-1][j+1]){
//                     continue;
//                 }
//                 else if(i!=m-1 && j==n-1 && !obstacleGrid[i+1][m-1]){
//                     dp[i][m-1]=dp[i+1][m-1];
//                 }
//                 else if(i!=m-1 && j==n-1 && obstacleGrid[i+1][m-1]){
//                     continue;
//                 }
//                 else if(i!=m-1 && j!=n-1 && !obstacleGrid[i+1][j] && !obstacleGrid[i][j+1]){
//                     dp[i][j]=dp[i][j+1]+ dp[i+1][j];
//                 }
//                 else if(i!=m-1 && j!=n-1 && obstacleGrid[i+1][j] && !obstacleGrid[i][j+1]){
//                     dp[i][j]=dp[i][j+1];
//                 }
//                 else if(i!=m-1 && j!=n-1 && !obstacleGrid[i+1][j] && obstacleGrid[i][j+1]){
//                     dp[i][j]=dp[i+1][j];
//                 }
//                 else if(i!=m-1 && j!=n-1 && obstacleGrid[i+1][j] && obstacleGrid[i][j+1]){
//                     continue;
//                 }
//             }
//         }
//         int ans = obstacleGrid[0][0]==1 ? 0 : dp[0][0];
//         return ans;
//     }
// };

// int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
//     int m = obstacleGrid.size();
//     int n = obstacleGrid[0].size();

//     if(i==m-1 && j==n-1){ return 1;}
//     if(i+1>m || j+1>n){return 0;}
//     if(i<m-1 && j<<n-1 && obstacleGrid[i][j]==1){return 0;}

//     if(dp[i][j]!=-1){return dp[i][j];}

//     int right = f(i+1,j,obstacleGrid,dp);
//     int down = f(i,j+1,obstacleGrid,dp);
//     return dp[i][j]=down+right;

// }

int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(i==m-1 && j==n-1){ 
        return obstacleGrid[i][j] == 1 ? 0 : 1;
    }
    if(i+1>m || j+1>n || obstacleGrid[i][j]==1){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int right = f(i+1,j,obstacleGrid,dp);
    int down = f(i,j+1,obstacleGrid,dp);
    return dp[i][j]=down+right;
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,obstacleGrid,dp);
    }
};

