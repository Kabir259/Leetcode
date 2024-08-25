#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxi = 0;

        for(int i = 0; i<n; i++){
            if(nums[i]==1){
                count++;
            }
            if(nums[i]==0){
                count=0;
            }
            maxi = max(maxi,count);
        }
        
        return maxi;
    }

};