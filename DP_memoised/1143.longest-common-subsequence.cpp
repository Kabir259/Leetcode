#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];

    int f(string t1, string t2, int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        else if(dp[n-1][m-1]!=-1) return dp[n-1][m-1];
        else if(t1[n-1]==t2[m-1]){
            return dp[n-1][m-1] = 1 + f(t1,t2,n-1,m-1);
        }
        return dp[n-1][m-1] = max(f(t1,t2,n-1,m),f(t1,t2,n,m-1));

    }

    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        if(n==0 || m==0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return f(t1,t2,n,m);

    }

};