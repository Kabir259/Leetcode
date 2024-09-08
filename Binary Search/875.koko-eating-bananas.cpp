#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int hours_taken(int mid, vector<int>& piles){
        int sum = 0;
        for(auto elt: piles){
            sum+= elt%mid==0 ? elt/mid: elt/mid+1;
        }
        return sum;
    }

    bool predicate(int mid, vector<int>& piles, int h){
        return hours_taken(mid,piles)<=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());

        while(l<r){
            int m = (l+r)/2;
            if (predicate(m, piles, h)) {
                r = m;  
            } else {
                l = m + 1;  
            }
        }
        return l;
    }
};
// @lc code=end

