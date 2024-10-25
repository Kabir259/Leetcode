/*
 * @lc app=leetcode id=1611 lang=cpp
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int dp[31]; // dont take size = 32
        dp[0]=1;

        for(int i = 1; i<31; i++){
            dp[i] = 2*dp[i-1] +1;
        }

        int operation = 0;
        bool positive = true;

        for(int i = 30; i>=0; i--){
            if((n & (1LL << i)) != 0){ // NOT == 0. MIND THE SPACES
                operation = positive? operation+dp[i]:operation-dp[i];
                positive = !positive;
            }
            else{
                continue;
            }
        }
        return operation;
    }
};
// @lc code=end

