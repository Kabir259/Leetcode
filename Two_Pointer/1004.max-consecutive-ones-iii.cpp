#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int k){
        int n = nums.size();
        int i =0 ,j =0;
        int maxi = 0;
        int countzeroes=0;
      //  unordered_map<int,int> m;

        while(j<n){
            int fwd = nums[j];
            if(fwd==0){
                countzeroes++;
            }
            if(countzeroes>k){
                int bwd = nums[i];
                if(bwd==0){
                    countzeroes--;
                }
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }

    int longestOnes(vector<int>& nums, int k) {
        return f(nums,k);
    }

};