/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);  

        for (int i = 0; i <= n; i++) {
            result[i] = __builtin_popcount(i); // its return type is int not void!!! 
        }

        return result;
    }
};
// @lc code=end

