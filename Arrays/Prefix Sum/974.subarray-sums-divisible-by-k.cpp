#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        int sum = 0;
        int count = 0;

        // map: remainder->frequency of occurance of subsets whose sum%k gives that remainder
        
        map<int,int> m; 
        /*
        stores the frequency of remainders when the cumulative sum is divided by k. 
        The key is the remainder, and the value is the frequency of that remainder.
        */ 
        m[0] = 1; // since -ve no.s exist, when you will encounter a sum of 0 for the first time, it wont be present in the map
        // and you will end up adding to the map. but you KNOW that 0%k=0. that means theres 1 way to divide 0 by k. since we are counting 
        // no. of ways this was init with m[0]=1;

        for(int i =0; i<n; i++){
            //MAKE ROLLING SUM
            sum+=nums[i];
            // DO MODULO ON THE ROLLING SUM. 
            sum%=k;// this was done to take modulo. earlier, no operator was placed on sum thats why we didnt do anything
            // this remainder tells us if the current cumulative sum is divisible by k or how far off it is from being divisible by k.
            sum+=k;
            sum%=k;// these three lines are standard procedure to take modulo of -ve no.s. -ve input is allowed
        
            if(m.find(sum)!=m.end()){ // dont do the m.find(sum%k)!=m.end(). we already computed sum%k in the calculation above
                // count++; // incorrect as you must increase count by the no. of ways you couldve modulo-ed sum. this is m[sum]
                count+=m[sum]; // increase count by the frequency of occurance of subsets that were divisible by k
            }
            m[sum]++; // increase frequency by one as you just encountered it

        }
        return count;

    }

};