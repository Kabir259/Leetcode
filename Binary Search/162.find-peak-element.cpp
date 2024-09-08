#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    bool p(int m, vector<int>& nums){
        if(nums[m]>nums[m+1]){
            // in downstream, move r towards peak bwd
            return true;
        }
        return false;
    }

    int findPeakElement(vector<int>& nums) {
        int  l =0; int r = nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(p(m,nums)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return l ;
    }
};
// @lc code=end

