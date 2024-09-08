#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool predicate(int min_cap,vector<int>& nums, int k){
        int day = 1;
        int sum = 0;
        for(auto elt: nums){
            sum+=elt;
            if(sum>min_cap){
                sum = elt;
                day++;
                if(day>k){
                    return false;
                }
            }
        }
        return true;
        
    }
    int splitArray(vector<int>& nums, int k) {
        // same as 1011 ship within d days

        int l = *max_element(nums.begin(),nums.end());
        int sum = 0;
        for(auto x: nums){
            sum+=x;
        }
        int r = sum;

        while(l<r){
            int m = (l+r)/2;
            if(predicate(m,nums,k)){
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

