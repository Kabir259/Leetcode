#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101];

    int f(vector<int>& nums, int n) {
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (dp[n] != -1) return dp[n];
        return dp[n] = max(nums[n-1] + f(nums, n-2), f(nums, n-1));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // Case 1: Rob houses from 0 to n-2
        memset(dp, -1, sizeof(dp));
        vector<int> n1(nums.begin(), nums.end() - 1);
        int x = f(n1, n1.size());

        // Case 2: Rob houses from 1 to n-1
        memset(dp, -1, sizeof(dp));
        vector<int> n2(nums.begin() + 1, nums.end());
        int y = f(n2, n2.size());

        return max(x, y);
    }

};