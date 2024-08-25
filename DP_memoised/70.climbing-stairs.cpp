#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[46];

    int f(int n){
        // base case for which trans exists
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else{
            if(dp[n]!=-1){
                return dp[n];
            }
            else{
                dp[n] = f(n-1) + f(n-2);  // Update dp[n] with the result
                return dp[n];
            }
        }
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }

};