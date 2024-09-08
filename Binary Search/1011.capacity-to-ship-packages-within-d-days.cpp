#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool predicate(int min_cap, vector<int>& weights, int days){
        int day = 1;
        int total = 0;
        for(auto weight:weights){
            total+=weight;
            if(total>min_cap){
                total=weight;
                day++;
                if(day>days){
                    return false;
                }
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        /*
        The issue many people have when it comes to understanding how a problem like this can 
        be approached using binary search comes down to the way most people learn binary search at 
        first. The traditional implementation of binary search which is shown to most first-time 
        learners gives the impression that the array in question must be sorted, however, the 
        reality is that binary search only cares about a "sorted" search space. Most people assume 
        that the search space of the binary search algorithm has to be the specific elements at a 
        given index in the given array, because those are the examples people tend to be shown when 
        learning binary search. In more advanced binary search problems such as this one, the real 
        trick is figuring out two things: the search space and the condition.

        In this problem the search space is the range between the min possible capacity of the 
        ship (which is the max weight of a single package in the entire array) and the max capacity 
        of a ship, which is the total of all the weights of the packages. We can justify this by 
        realizing the max a ship will need to hold is when you put all the packages on it at once, 
        and the minimum a ship needs to be able to hold is the heaviest package in the array. Now 
        we can see that the search space is going to be a range from min->max, which will be sorted 
        inherently by the fact that every number in the range is larger than the previous one.

        Now to identify the condition: Essentially if we find our "mid" which is the middle of the 
        range we are searching, we can use that as the ship capacity for the iteration, and then 
        determine how long (how many days) it takes us to pack the boats using this given capacity. 
        If we finish too fast (or on time), we know that we have found a valid capacity, and want to
        look for a smaller one (since we need to minimize the capacity) so we will look to the left of
        mid. If we finish too slow, we know that our capacity was not big enough to finish in time 
        (or at all), and therefore we need to look to the right of mid for a bigger capacity. 
        We keep doing this until we find the smallest capacity possible to get the packages shipped 
        in the allotted time period.
        
        In short: If we want to minimize or maximize something based on a specific condition, 
        we probably can use binary search. To use it, we need to identify the search space 
        (which does not have to be the array itself unlike in a traditional binary search problem), 
        and the condition.
        */
        int l = *max_element(weights.begin(),weights.end());
        int sum = 0;
        for(auto x:weights){
            sum+=x;
        }
        
        int r = sum;

        while(l<r){
            int m = (l+r)/2;
            if(predicate(m,weights,days)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return l;

    }
};
// @lc code=end

