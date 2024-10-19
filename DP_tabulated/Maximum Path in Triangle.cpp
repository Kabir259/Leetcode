#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>>& A, vector<vector<int>>& dp){
    int m = A.size();
    int n = A[i].size();

    if(i >= m) return 0;
    if(dp[i][j]!= -1) return dp[i][j];

    return dp[i][j]  = A[i][j]+max(rec(i+1,j,A,dp),rec(i+1,j+1,A,dp));

}


// Solution::
int solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[m-1].size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

    // int maxi = INT_MIN;

    // for(int i = 0; i<n; i++){
    //     int x = rec(0,0,m-1,i,A,dp);
    //     maxi =  max(maxi,x);
    // }
    // return maxi;

    return rec(0,0,A,dp);
}