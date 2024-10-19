#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Solution::

int solve(vector<vector<int> > &A) {
    int m = A.size();
    if (m == 0) return -1;
    int n = A[0].size();
    if (A[0][0] >= A[m-1][n-1]) return -1;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    /*
    Recurrence Relation:
    If(A[i][j] > A[i][j-1]) 
        dp[i][j] = max(dp[i][j], dp[i][j-1] + 1)
    If(A[i][j] > A[i-1][j]) 
        dp[i][j] = max(dp[i][j], dp[i-1][j] + 1)
    */

    dp[0][0] = 1;  


    for (int j = 1; j < n; j++) {
        if (A[0][j] > A[0][j-1]) {
            dp[0][j] = dp[0][j-1] + 1;
        }
    }

    for (int i = 1; i < m; i++) {
        if (A[i][0] > A[i-1][0]) {
            dp[i][0] = dp[i-1][0] + 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (A[i][j] > A[i][j-1]) {
                dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
            }
            if (A[i][j] > A[i-1][j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
            }
        }
    }

    return dp[m-1][n-1] == 0 ? -1 : dp[m-1][n-1];
}
