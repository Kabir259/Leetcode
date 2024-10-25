/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&](int& a, int& b){
            // return a<b for ascending
            // return a>b for desc
            int onesA  = __builtin_popcount(a);
            int onesB  = __builtin_popcount(b);
            if(onesA==onesB) return a<b; // asc by og value
            return onesA<onesB; // asc by count of 1s
        };

        sort(arr.begin(),arr.end(),lambda); 

        return arr;
        
    }
};
// @lc code=end

