#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        dp[n][0] = dp[n][1]= 0; // base case

        for(int i = n-1; i>=0; i--){
            for(int b = 0; b<=1; b++){
                int op1,op2;

                if(b==0){
                    op1= dp[i+1][0];
                    op2 = dp[i+1][1] -prices[i];
                }
                else{

                    op1= dp[i+1][1];
                    op2 = dp[i+1][0] +prices[i];
                }
                dp[i][b]= max(op1,op2);
            }
        }

        return dp[0][0];

    }

};