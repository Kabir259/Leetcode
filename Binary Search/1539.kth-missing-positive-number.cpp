#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> v(n);
        v[0] = arr[0]-1;

        for(int i = 1; i<n; i++){
            if(arr[i-1]!=arr[i]-1){
                v[i]=arr[i]-(i+1);
            }
            else{
                v[i]=v[i-1];
            }
        }

        int l = 0;
        int r = n;
        while(l<r){
            int m = (l+r)/2;
            if(k<=v[m]){
                r = m;
            }
            else{
                l = m+1;
            }
        }

        if(l==0) return k;
        
        return (arr[l-1] + k - v[l-1]);
    }
};
// @lc code=end

