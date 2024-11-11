#include <iostream>
#include <bits/stdc++.h>
using namespace std;



// Solution::
int solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    int maxi = INT_MIN;

    for(int i = m-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            dp[i][j] = dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1]+A[i][j];
            maxi = max(maxi,dp[i][j]);
        }
    }

    return maxi;
}