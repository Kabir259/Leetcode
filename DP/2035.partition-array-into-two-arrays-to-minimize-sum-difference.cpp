/*
 * @lc app=leetcode id=2035 lang=cpp
 *
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start



// THIS QUESTION IS NOT FROM DP ITS FROM BINARY SEARCH MEET IN THE MIDDLE ALGORITHM
// THIS QUESTION IS NOT FROM DP ITS FROM BINARY SEARCH MEET IN THE MIDDLE ALGORITHM
// THIS QUESTION IS NOT FROM DP ITS FROM BINARY SEARCH MEET IN THE MIDDLE ALGORITHM
// THIS QUESTION IS NOT FROM DP ITS FROM BINARY SEARCH MEET IN THE MIDDLE ALGORITHM
// THIS QUESTION IS NOT FROM DP ITS FROM BINARY SEARCH MEET IN THE MIDDLE ALGORITHM




class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int minNum = *min_element(nums.begin(), nums.end());
        int shift = minNum < 0 ? -minNum : 0; // calculate the shift for negative numbers
        int range = 0;
        for(int i = 0; i < n; i++){
            nums[i] += shift; // shift all numbers to non-negative
            range += nums[i];
        }
        
        vector<vector<int>> dp(n+1,vector<int>((range)+1));
            for(int i =0;i<=n;i++){
                for(int j=0;j<=range/2;j++){
                    if(i==0 || j==0){
                        dp[i][j]=0;
                    }
                }
            }
            for(int i =1;i<=n;i++){
                for(int j=0;j<=range;j++){
                    if(nums[i-1]<=j){
                        dp[i][j]=max(nums[i-1]+dp[i-1][j-nums[i-1]],dp[i-1][j]);
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        
        int ans = 1e9;
        for(int j=0;j<=range/2;j++){
            ans=min(ans,range-2*dp[n][j]);
        }
        return ans;
    }
};
// @lc code=end

