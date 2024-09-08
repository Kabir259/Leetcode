#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:



    int f(int m, vector<int>& nums, int target){
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+= min(nums[i],m);
        }
        return abs(sum-target);

    }

    bool p(int m, vector<int>& nums, int target){
        if(f(m,nums,target)<=f(m+1,nums,target)){
            // in downstream, move r towards valley
            return true;
        }
        return false;
    }

    int findBestValue(vector<int>& arr, int target) {
        int  l =0; int r = *max_element(arr.begin(),arr.end());
        while(l<r){
            int m = (l+r)/2;
            if(p(m,arr,target)){
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

