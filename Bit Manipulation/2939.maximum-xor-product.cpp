#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int bit = 0;
        int x = 0;
        const int mod = 1e9+7;

        while(bit<n){
            if(!(a&(1<<bit)) && !(b&(1<<bit))) x|=(1<<bit);
            // else if((a&1<<bit) && (b&1<<bit)) continue;
            if(a>b && (a&(1<<bit)) && !(b&(1<<bit))) x|=(1<<bit);
            if(a<b && !(a&(1<<bit)) && (b&(1<<bit))) x|=(1<<bit);
            bit++;
        }
        return ((a^x)*(x^b))%mod;
    }
};
// @lc code=end

