#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[101][101];

    int f(vector<vector<int>>& obstacleGrid, int m, int n){
        if(m<=0 || n<=0 || obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        else if(m==1 && n==1){
            return 1;
        }
        else{
            if(dp[m-1][n-1]!=-1){
                return dp[m-1][n-1];
            }
            else{
                return dp[m-1][n-1] = f(obstacleGrid,m-1,n)+f(obstacleGrid,m,n-1);
            }
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m<=0 || n<=0 || obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1){
            return 0;
        }

        return f(obstacleGrid,m,n);
    }

};