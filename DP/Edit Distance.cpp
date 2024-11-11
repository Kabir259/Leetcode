#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fl(i,m,n) for(int i =m;i<n;i++)
#define rfl(i,m,n) for(int i =m;i>=n;i--)


// Solution::
int minDistance(string A, string B) {
    int m = A.size();
    int n = B.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1));

    fl(i,0,m+1){
        fl(j,0,n+1){
            if(i ==m) dp[i][j]=m-j;
            if(j ==n) dp[i][j]=n-i;
        }
    }

    rfl(i,m-1,0){
        rfl(j,n-1,0){
            if(A[i]==B[j]) dp[i][j]=dp[i+1][j+1];
            else dp[i][j]=1+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
    }

    if(dp[0][0]==0){
        return abs(m-n);
    }
    else{
        return dp[0][0];
    }
}