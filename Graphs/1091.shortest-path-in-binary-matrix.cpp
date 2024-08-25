/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0]!=grid[n-1][m-1]){
            return -1;
        }

        if (n == 1 && grid[0][0] == 0) {
            return 1; // Edge case for single element 0 grid
        }

        if (n == 1 && grid[0][0] == 1) {
            return -1; // Edge case for single element 1 grid
        }

        set<pair<int,pair<int,int>>> st; // d,i,j
        st.insert({1,{0,0}});

        vector<vector<int>> dis(n,vector<int>(n,1e9));
        dis[0][0]=1;

        int dx[8] = {0,0,1,-1,1,1,-1,-1};
        int dy[8] = {1,-1,0,0,1,-1,1,-1};

        while(!st.empty()){
            auto it = *(st.begin());
            int i = it.second.first;
            int j = it.second.second;
            int disUntilNow = it.first;
            st.erase(it);

            for(int k = 0; k<8; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                int nd = disUntilNow+1;

                bool valid = ni>=0 && ni<n && nj>=0 && nj<m;
                if(valid && grid[ni][nj]==0){
                    if(nd<dis[ni][nj]){
                        if(dis[ni][nj]!=1e9){
                            st.erase({dis[ni][nj],{ni,nj}});
                        }

                        dis[ni][nj]=nd;
                        st.insert({dis[ni][nj],{ni,nj}});
                    }
                }
            }
        }

        return dis[n-1][m-1]==1e9?-1:dis[n-1][n-1];

    }
};
// @lc code=end

