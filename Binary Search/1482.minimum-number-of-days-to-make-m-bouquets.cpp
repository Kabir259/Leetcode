#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:

    bool predicate_have_m_bouquets_been_made_by_now(
        int mid, vector<int>& bloomDay, int m, int k){
            int bloomed = 0;
            int bouquets = 0;

            for(int i = 0; i<bloomDay.size(); i++){
                if(mid>=bloomDay[i]){
                    bloomed++;
                    if(bloomed==k){
                        bouquets++;
                        bloomed=0;
                    }
                }

                // bloomed = 0; // THIS GIVES WRONG BUT USING ELSE GIVES RIGHT ANSWER????
                

                else{
                    bloomed = 0;
                }
                
                if(bouquets>=m){
                    return true;
                }
            }
            // if(bouquets>=m){
            //     return true;
            // }
            // return bloomed==m; // WRONG CONDITION. return bllomed>=m to account for entire right house
            return false;
        }

    
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long totalFlowersNeeded = (long long)m * k;
        if (bloomDay.size() < totalFlowersNeeded) {
            return -1;  // impossible to make m bouquets
        }

        int l = *min_element(bloomDay.begin(),bloomDay.end()); // unit = day
        int r = *max_element(bloomDay.begin(),bloomDay.end()); // unit = day

        while(l<r){
            int mid = (l+r)/2; // unit = day
            if(predicate_have_m_bouquets_been_made_by_now(mid, bloomDay, m, k)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
// @lc code=end

