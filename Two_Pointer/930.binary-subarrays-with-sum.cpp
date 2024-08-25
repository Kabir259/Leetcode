#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i =0;
        int j = 0;

        int count = 0;
        int sum = 0;
        while(j<n){
            int fwd = nums[j];
            sum+=fwd;


            while(sum>goal){
                int bwd = nums[i];

                sum-=bwd;
                // count--;

                i++;
                
            }



            // count++;
            count += j-i+1;




            j++;
        }
        return count;
    }

};