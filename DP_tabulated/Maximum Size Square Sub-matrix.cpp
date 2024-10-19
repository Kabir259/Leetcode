#include <iostream>
#include <bits/stdc++.h>
using namespace std;




// Solution::
int solve(vector<vector<int> > &A) {
    int m = A.size();
    if(m==0) return 0;
    int n = A[0].size();
    if(n==0) return 0;

    vector<vector<int>> dp(m+1,vector<int>(n,0));
    int maxi = 0;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(A[i-1][j-1]==0) continue;
            else {
                dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                maxi = max(maxi,dp[i][j]);
            }
        }
    }

    
    // for(int i = 0; i<=m; i++){
    //     for(int j = 0; j<=n; j++){
    //         maxi = max(maxi,dp[i][j]);
    //     }
    // }
    return maxi*maxi;
}
