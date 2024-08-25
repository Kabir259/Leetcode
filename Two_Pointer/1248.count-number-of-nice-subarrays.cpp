#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count= 0;
        int ans = 0;
        

        while(j<n){
            int fwd = nums[j];
            if(fwd%2==1) count++;

            while(count>k){
                int bwd = nums[i];

                if(fwd%2==1){
                    count--;
                }

                i++;
            }
            


            if(count==k) ans++;

            j++;
        }    
        return ans;    
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k);        
    }

};