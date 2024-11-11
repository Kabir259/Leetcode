#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[101];

    // int f(vector<int>& nums){
    //     int n = nums.size();
    //     if(n==0){
    //         return 0;
    //     }
    //     else if(n==1){
    //         return nums[0];
    //     }
    //     else if(n==2){
    //         return max(nums[0],nums[1]);
    //     }
    //     else{
    //         if(dp[n-1]!=-1){
    //             return dp[n-1];
    //         }
    //         else{
    //             vector<int> n1(nums.begin(),nums.end()-1);
    //             vector<int> n2(nums.begin(),nums.end()-2);
    //             return dp[n-1] = max(nums[n-1]+f(n2), f(n1));
    //         }
    //     }

    // }

    // inefficient copying of vectors

    // int rob(vector<int>& nums) {
    //     memset(dp,-1,sizeof(dp));
    //     return f(nums);

    // }

    int f(vector<int>& nums, int n) {
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (dp[n] != -1) return dp[n];
        return dp[n] = max(nums[n-1] + f(nums, n-2), f(nums, n-1));
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(nums, nums.size());
    }  

};
