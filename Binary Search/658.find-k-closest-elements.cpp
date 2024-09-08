#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size()-k; // converting sliding window to binary search

        while(l<r){
            int m = (l+r)/2;
            if((x-arr[m])<=(arr[m+k]-x)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        
        return vector<int>(arr.begin()+l,arr.begin()+l+k);

    }
};
// @lc code=end

