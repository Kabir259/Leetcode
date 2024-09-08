#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    

    bool predicate(int m, vector<int>& nums){

        if((m % 2 == 0 && m + 1 < nums.size() && nums[m]!=nums[m+1])
        || (m % 2 == 1 && m + 1 < nums.size() && nums[m]==nums[m+1])){
            return true;
        }

        return false;
    }
    int singleNonDuplicate(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(predicate(m,nums)){
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

