#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    bool p(int m, vector<int>& nums, int target){
        // check condiiton for being in same house. arr = [house1 | house2];
        /*a house means it has increasing elts only
        if in same house, bin search works
        if in diff house: forcefuly make an incrreasing array
        if mid ptr in smaller house [0 1 2] in [4 5 6 7 | 0 1 2]
        and tgt>mid , lower house elts-> inf
        
        vice versa:
        bigger house elts -> -inf*/

        // predicate p(m) always returns mininimum m st nums[m]>=target

        int val;

        if(nums[m]<nums[0] == target<nums[0]){
            val = nums[m];
        }
        else{
            if(target>nums[m]){
                val=INT_MAX;
            }
            else{
                val=INT_MIN;
            }
        }
        return val>=target;
    }


    int search(vector<int>& nums, int target) {
        int l =0; int r = nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(p(m,nums,target)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        if(nums[l]==target){
            return l;
        }
        return -1;

    }
};
// @lc code=end

