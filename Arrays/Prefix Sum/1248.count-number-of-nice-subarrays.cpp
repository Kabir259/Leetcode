#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }

        //means you will only highlight odd no.s as one

        int sum = 0;
        int count = 0;

        map<int,int> m; // odd sum -> freq
        m[0]=1; // [WRONG LOGIC]: sum of 0 means you havent encountered any odd no. yet.
        // [RIGHT LOGIC]: sum of 0 means you have encountered a sum 0 once, that too at initialisation

        for(int i = 0; i<n; i++){
            sum+=nums[i];

            if(m.find(sum-k)!=m.end()){
                count += m[sum-k];
            }
            m[sum]++;
        }
        return count;
    }

};