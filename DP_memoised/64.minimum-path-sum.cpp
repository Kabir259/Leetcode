#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[201][201];

    int f(vector<vector<int>>& grid, int m, int n){
        if(m<=0 || n<=0){
            return INT_MAX; 
            // use inf for outof bounds when using min funcn in trans eqn
        }
        else if(m==1 && n==1){
            return grid[m-1][n-1];
        }
        else if(dp[m-1][n-1]!=-1){
            return dp[m-1][n-1];
        }
        return dp[m-1][n-1] = grid[m-1][n-1]+min(f(grid,m-1,n),f(grid,m,n-1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        if(m<=0 || n<=0){
            return 0;
        }
        return f(grid,m,n);

    }

};