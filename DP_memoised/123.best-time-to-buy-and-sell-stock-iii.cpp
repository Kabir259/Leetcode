#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int b, int c, vector<int>& prices, 
    vector<vector<vector<int>>> &dp , int n){
        if(i==n || c ==3){
            return 0;
        }
        if(dp[i][b][c]!=-1) return dp[i][b][c];
        int op1,op2;
        if(b==0){
            op1= f(i+1,0,c,prices,dp,n);
            op2 = f(i+1,1,c+1,prices,dp,n) -prices[i];
        }
        else{
            op1= f(i+1,1,c,prices,dp,n);
            op2 = f(i+1,0,c,prices,dp,n) +prices[i];
        }
        return max(op1,op2);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,0,0,prices,dp,n);
    }
};