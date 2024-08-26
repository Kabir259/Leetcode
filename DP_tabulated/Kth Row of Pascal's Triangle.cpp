#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    vector<vector<int>> dp;


    vector<int> Solution::getRow(int k) {
        vector<vector<int>> dp(k+1,vector<int>(k+1,0));
        // dp[no. , column]
        
        for(int i = 0; i<k+1; i++){
            dp[i][i]=1;
            dp[i][0]=1;
        }
        
        for(int i = 1; i<k+1; i++){
            for(int j = 1; j<i; j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }
        
        return dp[k];
        
        
    }

};