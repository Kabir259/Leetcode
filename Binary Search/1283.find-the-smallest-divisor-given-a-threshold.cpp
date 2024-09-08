#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    bool predicate(int m, vector<int>& nums, int threshold){
        int sum = 0;
        for(auto elt: nums){
            // sum+=elt/m;
            sum+=(elt+m-1)/m; // you have to round up the division
        }
        return sum<=threshold;

    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1; // division sum
        int r = *max_element(nums.begin(),nums.end());// division sum

        while(l<r){
            int m = (l+r)/2; // division sum
            if(predicate(m, nums, threshold)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return l;
    }
};
// @lc code=end

