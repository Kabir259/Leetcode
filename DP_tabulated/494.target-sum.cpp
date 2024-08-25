/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = nums.size();
        int range = 0; // Initialize range correctly
        for (int i = 0; i < m; i++) {
            range += nums[i];
        }

        // Check if (target + range) is valid and even
        if ((target + range) % 2 != 0 || abs(target) > range) {
            return 0;
        }

        int s1 = (target + range) / 2;

        // dp table init: i size of array, j target
        // first col including 0,0: j=0, i: 1 way, first row: 0 ways
        vector<vector<int>> dp(m + 1, vector<int>(s1 + 1, 0));

        for (int j = 0; j <= s1; j++) {
            dp[0][j] = 0; // There's no way to make sum: from empty aarray
        }

        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1; // There's one way to make sum 0: by not picking any element
        }

        // table initialized
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= s1; j++) {
                // dp[i][j] is next state, i-1 is previous state row
                // nums[i-1] is correct not nums[i] as if nums = {1,2,3} then dp={0,1,2,3}, dp is one offset behind nums
                // nums[i-1] represents the value we have chosen to put in knapsack, dp[i-1] represents transition from previous state to current state
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // we have the last row initialized with the number of ways now
        return dp[m][s1];
    }
};
// @lc code=end
