#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fl(i,m,n) for(int i = m; i<n; i++)
#define rfl(i,m,n) for(int i = m; i>=n; i--)

// Solution::
int numDistinct(string A, string B) {

    int m = A.size(); // big string
    int n = B.size(); // small string
    
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    
    // fl(j,0,n+1){
    //     dp[0][j]=0;
    // }
    fl(i,0,m+1){
        dp[i][0]=1;
    }

    fl(i,1,m+1){
        fl(j,1,n+1){
            if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[m][n];

}
