#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minFlips(int a, int b, int c) {
        // min no of flips in both a n b to make their or == c
        int flips = 0;

        while(a||b||c){
            if(c&1){
                if(!(a&1) && !(b&1)){
                    flips++;
                }
            }
            else{
                if(a&1){
                    flips++;
                }
                if(b&1){
                    flips++;
                }
            }
            a>>=1; b>>=1; c>>=1;
        }

        return flips;
    }
};
// @lc code=end

