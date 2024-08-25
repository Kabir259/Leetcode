#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101];
    int f(int m, int n){
        if(m==0 || n==0){
            return 0;
        }
        else if(m==1 || n==1){
            return 1;
        }
        else{
            if(dp[m-1][n-1]!=-1){
                return dp[m-1][n-1];
            }
            else{
                return dp[m-1][n-1] = f(m-1,n)+f(m,n-1);
            }
        }
    }

    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(m,n);
    }

};