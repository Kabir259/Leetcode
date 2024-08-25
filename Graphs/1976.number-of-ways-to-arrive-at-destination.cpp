/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            adj[u].push_back({d, v});
            adj[v].push_back({d, u});
        }


        vector<int> dis(n, INT_MAX);
        vector<int> ways(n, 0);
        set<pair<int, int>> st;
        st.insert({0, 0});
        dis[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;

        while (!st.empty()) {
            auto it = *(st.begin());
            int d = it.first;
            int node = it.second;
            st.erase(it);


            for (auto [edgW, adjNode] : adj[node]) {
                int nd = d + edgW;
                if (nd < dis[adjNode]) {
                    if (dis[adjNode] != INT_MAX) {
                        st.erase({dis[adjNode], adjNode});
                    }
                    dis[adjNode] = nd;
                    st.insert({dis[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (nd == dis[adjNode]) {
                // DO NOT PUT IF HERE LEARN WHERE TO PUT IF AND WHERE TO PUT ELSE IF
                // WHENEVR YOU ARE TYPING CONDITIONALS AS > = < THEY ARE MUTUALLY EXCLUSIVE 
                // DONT NEED AN IF WITH THEM
                // MULTIPLE IFS ARE USED WHEN YOU WANT TO CHECK ALL THE CONDITIONS AND RUN THEM
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }

        }

        return ways[n-1] % mod;

    }
};
// @lc code=end

