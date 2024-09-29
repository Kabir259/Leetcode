#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        map<int,int> m;
        // map: sum -> frequency of occurance of that sum in some non empty subarray

        // int zeroes = 1;
        // for(int i = 0; i<n; i++){
        //     if(nums[i]==0) zeroes++;
        // }

        // m[0]=zeroes; //this is wrong logic of thinking m[0] = no. of zeroes already present in the array would give me a sum 0 so i will do m[0]=no. of zeroes
        m[0]=1; // before starting the subarray sum calculations you already have 0 sum. you have 1 occurance already initialised by definintion.
        int count = 0;
        int sum = 0;

        for(int i = 0; i<n; i++){
            sum+=nums[i];

            if(m.find(sum-goal)!=m.end()){
                count += m[sum-goal];
            }

        //    if(m.find(sum)!=m.end()){ // dont do this. even if you find the sum in the map, since you discovered it, you must increasy freq by 1.
                                        // by putting an if statement you are only increasing frequency when you encounter a new sum and skipping freq increase for already encountered sums

                m[sum]++; //increase frequency by 1 on discovery
        //    }

        }

        return count;
    }

};