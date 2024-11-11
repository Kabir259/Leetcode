/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */


#include <iostream>
#include <bits/stdc++.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;


// Spee


// Code-----------------------------------------------------------------------------------------------



// Main-----------------------------------------------------------------------------------------------


// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] represnents no. of ways you can reach m-1,n-1
        // transition: dp[i][j] = dp[i+1][j] + dp[i][j+1]
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i==m-1 && j==n-1){
                    dp[m-1][n-1]=1;
                }
                else if(i==m-1 && j!=n-1){
                    dp[m-1][j]=dp[m-1][j+1];
                }
                else if(i!=m-1 && j==n-1){
                    dp[i][n-1]=dp[i+1][n-1];
                }
                else if(i!=m-1 && j!=n-1){
                    dp[i][j]=dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];

    }
};
// @lc code=end

