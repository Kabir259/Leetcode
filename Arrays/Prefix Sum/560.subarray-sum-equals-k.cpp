#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        int count = 0;
        
        map<int,int> m; // map: sum-> frequency of subarrays with that sum
        m[0]=1;

        for(int i = 0; i<n; i++){
            sum+=nums[i];

            if(m.find(sum-k)!=m.end()){
                count+=m[sum-k];
            }

            m[sum]++; // found an occurance where a subset has this sum
        }
        return count;
    }

};