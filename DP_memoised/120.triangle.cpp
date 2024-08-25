#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[201][201];

    int f(vector<vector<int>>& triangle, int h, int w){
        if(h==0){
            return 0;
        }
        else if(w<0 || w>=triangle[h-1].size()){
            return INT_MAX;
        }
        else if(h==1 && w==1){
            return triangle[h-1][w];
        }
        else if(dp[h-1][w]!=-1){
            return dp[h-1][w];
        }
        return dp[h-1][w] = triangle[h-1][w]+min(f(triangle,h-1,w),f(triangle,h-1,w-1));

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        int w = triangle[h-1].size();
        if(h==0 || w==0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        int minn = INT_MAX;
        for(int i = 0; i<w; i++){
            minn = min(minn,f(triangle,h,i));
        }
        return minn;

    }

};