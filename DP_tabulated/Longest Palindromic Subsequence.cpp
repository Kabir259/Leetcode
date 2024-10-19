#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fl(i,m,n) for(int i = m; i<n; i++)
#define rfl(i,m,n) for(int i = m; i>=n; i--)


// Solution::
int solve(string A) {
    int m = A.size();
    string B(A.begin(),A.end());
    reverse(B.begin(),B.end());

    vector<vector<int>> dp(m+1,vector<int>(m+1));

    fl(i,0,m){
        fl(j,0,m){
            if(i==m || j==m) dp[i][j]=0;
        }
    }

    rfl(i,m-1,0){
        rfl(j,m-1,0){
            if(A[i]==B[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }

    return dp[0][0];

}
