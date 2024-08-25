#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[302][302];
    int f(int i, int j, vector<int>& nums){
        if(j<i){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = -1;
        for(int k = i; k<=j; k++){
            int cost = f(i,k-1,nums)+f(k+1,j,nums)+nums[k]*nums[i-1]*nums[j+1];
            // [(i.......)k(.........j)]
            // choose any elt from both options by calling recursion on both options
            // important to read the editorial for this one
            maxi = max(maxi,cost);
        }
        return dp[i][j]= maxi;
        
        
    }

    int maxCoins(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        int n = nums.size();

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        // return f(1,n,nums);

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i = n; i>=1; i--){
            for(int j = 0; j<=n; j++){
                if(i>j) continue;
                int maxi = -1;
                
                for(int k = i; k<=j; k++){
                    int cost = dp[i][k-1]+dp[k+1][j]+nums[k]*nums[i-1]*nums[j+1];
                    // [(i.......)k(.........j)]
                    // choose any elt from both options by calling recursion on both options
                    // important to read the editorial for this one
                    maxi = max(maxi,cost);
                }

                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }

};