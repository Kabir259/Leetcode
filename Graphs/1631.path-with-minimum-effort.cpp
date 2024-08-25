/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});

        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=0;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!st.empty()){
            auto it = *(st.begin());
            int i = it.second.first;
            int j = it.second.second;
            int d = it.first;

            if (i == n - 1 && j == m - 1) {
                return d;
            }

            st.erase(it);

            for(int k =0; k<4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];

                bool valid = ni>=0 && ni<n && nj>=0 && nj<m;

                if(valid){
                    int nd = max(abs(heights[ni][nj]-heights[i][j]),d);

                    if(nd<dis[ni][nj]){
                        if(dis[ni][nj]!=1e9){
                            st.erase({dis[ni][nj],{ni,nj}});
                        }

                        dis[ni][nj] = nd;
                        st.insert({dis[ni][nj],{ni,nj}});
                    }
                }
                
            }
        }

        return 0;

    }
};
// @lc code=end

