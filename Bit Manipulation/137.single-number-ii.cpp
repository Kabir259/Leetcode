#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // O(n) space is used if you maintain a frequency map
        int n = sizeof(int)*8;
        int result = 0;

        for(int bit = 0; bit<n; bit++){ // for every bit
            int ones = 0;

            for(int num = 0; num<nums.size(); num++){ // in every number
                // if(nums[num]&(1<<bit)==1) ones++; 
                // this doesnt work as order of precedence: == > & > != 
                //so it gets evaluated as nums[num]&(1<<bit==1)
                // hence use != 0 instead of == 1 

                // if(nums[num]&(1<<bit)!=0) ones++;
                // KEEP IN MIND THE SPACES

                if ((nums[num] & (1 << bit)) != 0) ones++;

            }
            
            if(ones%3!=0) result |= (1<<bit);


        }

        return result;
    }
};
// @lc code=end

