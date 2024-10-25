/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref[0]);

        for(int i = 1; i<pref.size(); i++){
            ans.push_back(pref[i]^pref[i-1]);
        }
        return ans;
    }
};
// @lc code=end

