#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    bool p(int m, int r, vector<int>& nums){
        if(nums[m]<nums[r]){
            // in lower house
            return true;
        }
        return false;
    }
    int findMin(vector<int>& nums) {
        int  l =0; int r = nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(p(m,r,nums)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return nums[l];
    }
};
// @lc code=end

