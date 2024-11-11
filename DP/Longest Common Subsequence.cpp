#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fl(i,m,n) for(int i = m;i<n;i++)
#define rfl(i,m,n) for(int i = m; i>=n; i--)

// int rec( int i , int j, string A, string B, vector<vector<int>>& dp){
//     if(i==A.size() || j==B.size()) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(A[i]==B[j]) return dp[i][j]=1+ rec(i+1,j+1,A,B,dp);
//     else return dp[i][j]=max(rec(i+1,j,A,B,dp),rec(i,j+1,A,B,dp));
// }

// Solution::

int solve(string A, string B) {
    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1));
    // return rec(0,0,A,B,dp);
    
    int m = A.size();
    int n = B.size();

    fl(i,0,m){
        fl(j,0,n){
            if(i==m || j==n) dp[i][j]=0;
        }
    }

    rfl(i,m-1,0){
        rfl(j,n-1,0){
            if(A[i]==B[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }

    return dp[0][0];

}