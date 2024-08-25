#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j =-1;
        
        for(int i=0; i<n; i++){ // place j on the first 0 in the arr
            if(nums[i]==0) {
                j=i; 
                break;
            }
        }

        // j is at first 0 of the arr
        if(j!=-1) { // provided there exists a 0 in the arr
            for(int i = j+1; i<n; i++){
                // look forward to the next non zero no.
                if(nums[i]!=0){
                    nums[j] = nums[i];
                    nums[i] = 0;
                    // swap(nums[i],nums[j]);
                    // j=i; this is wrong as j might jump over some 0 sandwhiched between nums[j] and nums[i]
                    j++;
                }
                continue;
            }
        }

    }

};