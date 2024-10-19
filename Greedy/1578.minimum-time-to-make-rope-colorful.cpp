#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        if(n==0 || n==1){
            return 0;
        }
        int i =0;
        int j = 1;
        int ans = 0;
        while (j < n) {
            if (colors[i] == colors[j]) {
                // If both colors are the same, we remove the one with smaller neededTime
                if (neededTime[i] <= neededTime[j]) {
                    ans += neededTime[i];
                    i = j; // Move `i` to `j` as `j` becomes the new reference
                } else {
                    ans += neededTime[j];
                }
            } else {
                i = j; // Move `i` to the next unique color
            }
            j++; // Move `j` to the next position
        }
        return ans;
    }
};
// @lc code=end

